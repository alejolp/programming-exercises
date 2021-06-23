#!/usr/bin/env python3

import glob
import hashlib
import json
import os
import subprocess
import sys
import time

def read_url(url, cookies_file):
    args = ["curl", "-b", cookies_file, "-X", "GET", url]
    result = subprocess.run(args, capture_output=True)
    data = json.loads(result.stdout.decode('utf-8'))
    return data

def main():
    cookies_file = sys.argv[1]
    problem_info = {}
    submissions = set()

    # build the set of code already submitted
    for filename in glob.glob('**', recursive=True):
        if os.path.isfile(filename):
            with open(filename, 'rb') as f:
                h = hashlib.sha1(f.read().strip()).hexdigest()
                submissions.add(h)

    # get the list of all problems
    data = read_url("https://leetcode.com/api/problems/all/", cookies_file)
    for elem in data['stat_status_pairs']:
        qname = elem['stat']['question__title']
        qid = elem['stat']['question_id']
        qslug = elem['stat']['question__title_slug']
        problem_info[qname] = {'id': qid, 'slug': qslug}

    offset = 0
    while True:
        time.sleep(5)
        # get the list of submissions
        data = read_url("https://leetcode.com/api/submissions/?offset={0}&limit=20&lastkey=".format(offset), cookies_file)
        print('Fetched offset {}'.format(offset))

        for elem in data.get('submissions_dump', []):
            if elem['status_display'].lower() == 'accepted':
                qcode = elem['code'].strip().encode('utf-8')
                qhash = hashlib.sha1(qcode).hexdigest()

                if elem['title'] in problem_info:
                    info = problem_info[elem['title']]
                    qid = "{0:04d}_{1}".format(info['id'], info['slug'])
                else:
                    qid = "{0}".format(elem['id'])
                qext = elem['lang']

                if qhash in submissions:
                    print('Already exists: {0}'.format(qid))
                    continue

                nextx = 1
                fname = 'tmp/{0}.{1}'.format(qid, qext)
                while os.path.exists(fname):
                    fname = 'tmp/{0}_{2}.{1}'.format(qid, qext, nextx)
                    nextx = nextx + 1

                with open(fname, 'wb') as wf:
                    wf.write(qcode)

        if len(data.get('submissions_dump', [])) < 20:
            break

        offset = offset + 20

if __name__ == '__main__':
    main()

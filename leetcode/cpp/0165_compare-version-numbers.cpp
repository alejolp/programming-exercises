class Solution {
public:
    int compareVersion(string version1, string version2) {
        version1 += ".0.0";
        version2 += ".0.0";
        int s1 = 0, s2 = 0;
        int p1 = version1.find('.');
        int p2 = version2.find('.');
        while (p1 != string::npos && p2 != string::npos) {
            int v1 = stoi(version1.substr(s1, p1 - s1));
            int v2 = stoi(version2.substr(s2, p2 - s2));
            if (v1 < v2) {
                return -1;
            } else if (v2 < v1) {
                return 1;
            }
            s1 = p1 + 1;
            s2 = p2 + 1;
            p1 = version1.find('.', s1);
            p2 = version2.find('.', s2);
        }
        int v1 = stoi(version1.substr(s1));
        int v2 = stoi(version2.substr(s2));

        if (v1 < v2) return -1;
        if (v2 < v1) return 1;
        return 0;
    }
};
class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        double L1x1,L1x2,L2x1,L2x2,L1y1,L1y2,L2y1,L2y2;
        L1x1 = p1[0]; L1x2 = q1[0]; L1y1 = p1[1]; L1y2 = q1[1];
        L2x1 = p2[0]; L2x2 = q2[0]; L2y1 = p2[1]; L2y2 = q2[1];
        double m1 = double(L1y2 - L1y1) / double(L1x2 - L1x1);
        double m2 = double(L2y2 - L2y1) / double(L2x2 - L2x1);
        if(m1 == m2) return "false";
        bool check1 = (L2y2 - L1y1) - m1*(L2x2 - L1x1) > 0 ? true : false;
        bool check2 = (L2y1 - L1y1) - m1*(L2x1 - L1x1) > 0 ? true : false;
        bool check3 = (L1y2 - L2y1) - m2*(L1x2 - L2x1) > 0 ? true : false;
        bool check4 = (L1y1 - L2y1) - m2*(L1x1 - L2x1) > 0 ? true : false;
        if((check1 and check2) or (!check1 and !check2)) return "false";
        if((check3 and check4) or (!check3 and !check4)) return "false";
        return "true";
    }
};

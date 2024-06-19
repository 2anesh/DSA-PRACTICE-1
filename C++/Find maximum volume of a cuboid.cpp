class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        double p=perimeter,a=area;
        double l=(p/2-sqrt(p*p/4-6*a))/6;
        return l*l*(p/4-2*l);
    }
};


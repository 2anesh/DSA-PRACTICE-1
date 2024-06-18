class Solution {
  public:
    int rectanglesInCircle(int r) {
        int count=0;
        int diameter = 2*r;
        for(int i=1;i<diameter;i++)
        {
            for(int j=1;j<diameter;j++)
            {   double diagonal=(double)(sqrt(i*i+j*j));
                if(diagonal<=diameter)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};


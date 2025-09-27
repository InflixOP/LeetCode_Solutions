class Solution {
public:
    int doubleArea(vector<int>& x, vector<int>& y, vector<int>& z)
    {
        return abs(x[0]*(y[1]-z[1]) + y[0]*(z[1]-x[1]) + z[0]*(x[1]-y[1]));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        int max=0;
        for(int i=0;i<points.size()-2;i++)
            for(int j=i+1;j<points.size()-1;j++)
                for(int k=j+1;k<points.size();k++)
                {
                    int aux=doubleArea(points[i],points[j],points[k]);
                    if(aux>max)
                        max=aux;
                }
        return (double)max/2;             
    }
};
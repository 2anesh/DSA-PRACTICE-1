class Solution {
public:    
    vector<double> gradient(vector<double>& pos, vector<vector<int>>& positions) {
        double vx = 0;
        double vy = 0;
        for (int i=0; i<positions.size(); i++) {
            double dx = positions[i][0] - pos[0];
            double dy = positions[i][1] - pos[1];
            double norm = sqrt(dx*dx + dy*dy);
            if (norm != 0) {
                double dx_n = dx / norm;
                double dy_n = dy / norm;
                vx += dx_n;
                vy += dy_n;
            }
        }
        vector<double> res = {vx, vy};        
        return res;
    }    
    double func_t(double t, const vector<double>& pos, const vector<vector<int>>& positions, const vector<double>& grad) 
    {
        vector<double> new_pos = {
            pos[0] + grad[0] * t,
            pos[1] + grad[1] * t};
        return sum_distances(new_pos, positions);
    }    
    double backtracking_line_search(const vector<double>& pos, const vector<vector<int>>& positions, const vector<double>& grad, double alpha, double beta) 
    {
        double y = sum_distances(pos, positions);
        double t = 1;
        double grad_norm = get_norm(grad);        
        while (func_t(t, pos, positions, grad) > y - alpha * grad_norm * grad_norm * t) {
            t *= beta;
        }
        return t;
    }    
    double get_norm(const vector<double>& vec) {
        double sum = 0;
        for (double ele : vec) {
            sum += ele * ele;
        }
        return sqrt(sum);
    }    
    double sum_distances(const vector<double>& pos, const vector<vector<int>>& positions) {
        double sum = 0;
        for (int i=0; i<positions.size(); i++) {
            double dx = (positions[i][0] - pos[0]);
            double dy = (positions[i][1] - pos[1]);
            sum += sqrt(dx*dx + dy*dy);
        }
        return sum;
    }    
    vector<double> start_point(const vector<vector<int>>& positions) {
        double x_sum = 0;
        double y_sum = 0;
        for (const vector<int>& pos : positions) {
            x_sum += pos[0];
            y_sum += pos[1];
        }
        return vector<double>{x_sum / positions.size(), y_sum / positions.size()};
    }   
    double getMinDistSum(vector<vector<int>>& positions) {
        vector<double> pos = start_point(positions);
        double grad_norm = 1;
        double t = 1;        
        while (t * grad_norm > 4.5e-6) {
            vector<double> grad = gradient(pos, positions);
            grad_norm = get_norm(grad);
            t = backtracking_line_search(pos, positions, grad, 0.5, 0.25);
            pos[0] += t * grad[0];
            pos[1] += t * grad[1];
        }
        return sum_distances(pos, positions);
    }
};

class Spreadsheet {
    unordered_map<string, int> cells;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        cells.erase(cell);
    }
    
    int getValue(string formula) {
        int idx = formula.find('+');
        string left = formula.substr(1, idx - 1);
        string right = formula.substr(idx + 1);

        int valLeft = 
            isalpha(left[0]) 
            ? (cells.count(left) ? cells[left] : 0) 
            : stoi(left);

        int valRight = 
            isalpha(right[0]) 
            ? (cells.count(right) ? cells[right] : 0) 
            : stoi(right);

        return valLeft + valRight;
    }
};
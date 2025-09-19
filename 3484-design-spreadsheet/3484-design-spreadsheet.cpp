class Spreadsheet {
    private:
        map<char, vector<int>> sheet;
        int rows; // CHANGED: store number of rows
    public:
        Spreadsheet(int rows_) {
            rows = rows_; // CHANGED
            vector<int> vec(rows, 0);
            for(char i='A'; i<='Z';i++){
                sheet[i]= vec;
            }
        }
        
        void setCell(string cell, int value) {
            char col= cell[0];
            int row= stoi(cell.substr(1)) - 1; // CHANGED: convert 1-based to 0-based
            if(row < 0 || row >= rows) return; // CHANGED: bounds check
            // cout<<col<<" "<<row<<endl;
            sheet[col][row]=value;
        }
        
        void resetCell(string cell) {
            char col = cell[0];
            int row = stoi(cell.substr(1)) - 1; // CHANGED
            if(row < 0 || row >= rows) return; // CHANGED
            sheet[col][row] = 0;
        }
        
        int getValue(string formula) {
            vector<string> operands;
            string word="";
            int cnt=0;
            for(int i=0;i<formula.length();i++){
                if(formula[i]=='+'){
                    operands.push_back(word);
                    word="";
                }
                if(formula[i]!='+' && formula[i]!='='){
                    word=word+formula[i];
                }
                if(formula[i]>='A'&& formula[i]<='Z'){
                    // cout<<"hello"<<endl;
                    cnt++;
                }
            }
            operands.push_back(word);
            // cout<<"hello"<<endl;
            // cout<<operands[0]<<" "<<operands[1]<<endl;
            // cout<<" cnt : "<<cnt<<endl;
            if(cnt==2){
                char col1= operands[0][0];
                char col2 = operands[1][0];
                int row1= stoi(operands[0].substr(1)) - 1; // CHANGED
                int row2= stoi(operands[1].substr(1)) - 1; // CHANGED
                if(row1 < 0 || row1 >= rows) return 0; // CHANGED: safety
                if(row2 < 0 || row2 >= rows) return 0; // CHANGED
                return sheet[col1][row1]+sheet[col2][row2];
            }
            if(cnt==1){
                if(operands[0][0]>='A' && operands[0][0]<='Z'){
                    char col= operands[0][0];
                    int row= stoi(operands[0].substr(1)) - 1; // CHANGED
                    if(row < 0 || row >= rows) return 0; // CHANGED
                    int val2= stoi(operands[1]); // operands[1] is numeric here
                    return sheet[col][row]+val2;
                }
                else{
                    char col = operands[1][0];
                    // cout<<"hello"<<endl;
                    int row = stoi(operands[1].substr(1)) - 1; // CHANGED
                    // cout<<"hello"<<row<<endl;
                    int val2 = stoi(operands[0]); // operands[0] is numeric here
                    if(row < 0 || row >= rows) return 0; // CHANGED
                    return sheet[col][row] + val2;
                }
            }
            if (cnt==0){
                // cout<<stoi(operands[0]);
                return stoi(operands[0])+stoi(operands[1]);
            }
            return 0;
        }
    };
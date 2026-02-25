class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k)
{
    // we would need to check first for T and then for F
    // for true
    int n = answerKey.length();
    int left =0;
    int cntFalse =0;
    int ansTrue=0;
    for(int right =0;right<n;right++){
        if(answerKey[right] == 'F'){
            cntFalse++;
        }
        while(cntFalse>k){
            if(answerKey[left] == 'F'){
                cntFalse--;
            }
            left++;
        }
        ansTrue = max(ansTrue, right-left);
    }

    left =0;
    int cntTrue=0;
    int ansFalse =0;
    for(int right =0;right<n;right++){
        if(answerKey[right] == 'T'){
            cntTrue++;
        }
        while(cntTrue>k){
            if(answerKey[left] == 'T'){
                cntTrue--;
            }
            left++;
        } 

        ansFalse = max(ansFalse, right - left);
    }
    return max(ansTrue, ansFalse) + 1;
}
};
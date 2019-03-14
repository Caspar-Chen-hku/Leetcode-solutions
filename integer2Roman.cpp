class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int remain = 0;
        int index = 0;
        string temp;
        while (num>0){
            temp = "";
            remain = num%10;
            num/=10;
            if (remain==0){
                index++;
                continue;
            }
            if (index==0){
                if (remain==9){
                    result = "IX";
                }else if (remain==4){
                    result = "IV";
                }else{
                    if (remain>=5){
                        result = "V";
                        remain -= 5;
                    }
                    for (int i=0; i<remain; i++){
                        result += "I";
                    }
                }
            } else if (index==1){
                if (remain==9){
                    result = "XC" + result;
                }else if (remain==4){
                    result = "XL" + result;
                }else{
                    if (remain>=5){
                        temp = "L";
                        remain -= 5;
                    }
                    for (int i=0; i<remain; i++){
                        temp += "X";
                    }
                    result = temp + result;
                }  
            } else if (index==2){
                if (remain==9){
                    result = "CM" + result;
                }else if (remain==4){
                    result = "CD" + result;
                }else{
                    if (remain>=5){
                        temp = "D";
                        remain -= 5;
                    }
                    for (int i=0; i<remain; i++){
                        temp += "C";
                    }
                    result = temp + result;
                }                 
            } else {
                for (int i=0; i<remain; i++){
                    result = "M" + result;
                }
            }
            index++;
        }
        return result;
    }
};
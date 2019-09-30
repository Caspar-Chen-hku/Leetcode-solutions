class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        tm time_in = { 0, 0, 0, day, month-1, year - 1900 };
        time_t time_temp = mktime(&time_in);
        const tm * time_out = localtime(&time_temp);
        
        switch (time_out->tm_wday){
            case 0:
                return "Sunday";
            case 1:
                return "Monday";
            case 2:
                return "Tuesday";
            case 3:
                return "Wednesday";
            case 4:
                return "Thursday";
            case 5:
                return "Friday";
            default:
                return "Saturday";
        }
    }
};
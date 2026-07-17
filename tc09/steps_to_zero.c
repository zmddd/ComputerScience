    /**
    *  给你一个非负整数 num ，请你返回将它变成 0 所需要的步数。 如果当前数字是偶数，你需要把它除以 2 ；否则，减去 1 。
    */
int numberOfSteps(int num) {
    if (num == 0){
        return 0;
    }

    if(num % 2){
        return numberOfSteps(num-1) + 1; 
    }
    return numberOfSteps(num/2) + 1; 
}
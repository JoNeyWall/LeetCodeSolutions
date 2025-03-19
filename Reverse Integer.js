/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let result = 0;
    let multiplier = 1;
    let place = 1000000000;
    let isLeadingZero = true;

    while(x !== 0){
      let valueToAdd = 0;
      //Ensure the same functionality of integer division where decimals are dropped.
      if (x > 0){
        valueToAdd = Math.floor(x / place) * multiplier;
      }
      else{
        valueToAdd = Math.ceil(x / place) * multiplier;
      }
      
      //We want to skip the leading zeros and only compute the actual value
      if(valueToAdd === 0 && isLeadingZero){
        place /= 10;
        continue;
      }
      isLeadingZero = false;

      //Check for overflow
      result += valueToAdd;
      if (result > 2147483647 || result < -2147483648){
        return 0;
      }

      //Prepare for the next iteration
      x = x % place;
      place /= 10;
      multiplier *= 10;
    }

    return result;
};
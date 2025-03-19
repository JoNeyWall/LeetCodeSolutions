/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    let isPositive = true;
    let atNumber = false;
    let stringNumber = "";
    let result = 0;

    for (let i = 0; i < s.length; i++){
        let current_char = s[i];

        if (current_char === " " && !atNumber){
          continue;
        }

        if (current_char === "-" && !atNumber){
          atNumber = true;
          isPositive = false;
          continue;
        }

        if (current_char === "+" && !atNumber){
          atNumber = true;
          isPositive = true;
          continue;
        }

        if (isNaN(current_char) || current_char === " "){
          break;
        }

        atNumber = true;
        stringNumber += current_char;
    }

    if (stringNumber === ""){
      return 0;
    }

    result = parseInt(stringNumber);
    if (!isPositive){
      result = -result;
    }
    
    if (result > 2147483647){
        return 2147483647;
    }

    if (result < -2147483648){
        return -2147483648;
    }

    return result;
};
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x < 0){
      return false; // Negative numbers are not palindromes
    }

    let str = x.toString(); // Convert the number to a string
    let reversedStr = str.split('').reverse().join(''); // Reverse the string
    return str === reversedStr; // Check if the original string is equal to the reversed string
};
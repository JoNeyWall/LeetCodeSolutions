/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows === 1){
      return s;
    }

    let spacing = 2 * (numRows - 1);
    let alt_spacing = 0;
    let result = "";
    let length = s.length;

    for (let i = 0; i < numRows; i++){
      let current_index = i;
      // first or last row
      if (i === 0 || i === numRows - 1){
        while (current_index < length){
          result += s[current_index];
          current_index += spacing;
        }
      }
      else{
        let alt = false;
        while (current_index < length){
          result += s[current_index];
          if (alt){
            alt = false;
            current_index += alt_spacing;
          }
          else{
            alt = true;
            current_index += spacing;
          }
        }
      }
      spacing -= 2;
      alt_spacing += 2;

      if (spacing === 0){
        spacing = 2 * (numRows - 1);
        alt_spacing = 0;
      }
    }

    return result;
};
// Linear Search algorithm. Takes the array to search, and the value to find
// Returns first index of query, or -1 if it is not present in the array
function linearSearch(arr, query) {
  // Loop through the array
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] === query) {
      // Break out of the loop and return current index
      return i;
    }
  }
  // Item was not found in the array: return -1
  return -1;
}

var arr = [1, 2, 3, 4, 5, 2];
var query = 2;
var result = linearSearch(arr, query);

if (result === -1) {
  console.log('Query value is not present in the array');
} else {
  console.log(`Query value is present at index: ${result}`);
}


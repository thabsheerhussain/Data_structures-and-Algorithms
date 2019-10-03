// swapping variables 
function swap(arr, i, j)
{
   var temp = arr[i];
   arr[i]   = arr[j];
   arr[j]   = temp;
}

function quickSort(arr, left, right)
{
   var len = arr.length, pivot,partitionIndex;

  if(left < right)
  {
    // picking last index as pivot
    pivot = right;

    // index from which list will be partitioned into two parts
    partitionIndex = partition(arr, pivot, left, right);
    
   //sort left and right both recursively
   quickSort(arr, left, partitionIndex - 1);
   quickSort(arr, partitionIndex + 1, right);
  }

  // now, the list has been sorted
  return arr;
}

function partition(arr, pivot, left, right)
{
   var pivotValue = arr[pivot],

   // take partitionIndex also to be at left
   // and start traversing from left to right
   partitionIndex = left;
   for(var i = left; i < right; i++)
   {
        // if element is smaller than pivot, we swap them,
        // and move the partitionIndex further
        if(arr[i] < pivotValue)
        {
          swap(arr, i, partitionIndex);
          partitionIndex++;
        }
  }

  // swapping element at 'right' index and at index 'partitionIndex'
  swap(arr, right, partitionIndex);
  return partitionIndex;
}

var list = [23,56,12,7,1];
quickSort(list,0,4);

// gives sorted list
console.log(list);

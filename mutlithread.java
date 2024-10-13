import java.util.Arrays;  
  
public class MultithreadedMergeSort   
{  
    private int[] array;  
    private int[] tempArray;  
  
    public void sort(int[] inputArray) {  
        this.array = inputArray;  
        int length = inputArray.length;  
        this.tempArray = new int[length];  
        mergeSort(0, length - 1);  
    }  
  
    private void mergeSort(int low, int high) {  
        if (low < high) {  
            int mid = (low + high) / 2;  
  
            // Create two separate threads to sort the left and right halves  
            Thread leftThread = new Thread(() -> mergeSort(low, mid));  
            Thread rightThread = new Thread(() -> mergeSort(mid + 1, high));  
  
            // Start both threads  
            leftThread.start();  
            rightThread.start();  
  
            try {  
                // Wait for both threads to complete  
                leftThread.join();  
                rightThread.join();  
  
                // Merge the sorted halves  
                merge(low,mid,high);  
            } catch (InterruptedException e)   
            {  
                e.printStackTrace();  
            }  
        }  
    }  
  
    private void merge(int low,int mid,int high)   
    {  
        // Copy both halves into the temporary array  
        System.arraycopy(array, low, tempArray, low, high - low + 1);  
  
        int leftIndex = low;  
        int rightIndex = mid + 1;  
        int currentIndex = low;  
  
        // Merge the two halves back into the original array  
        while (leftIndex <= mid && rightIndex <= high)   
        {  
            if (tempArray[leftIndex]<=tempArray[rightIndex])   
            {  
                array[currentIndex]=tempArray[leftIndex];  
                leftIndex++;  
            } else   
            {  
                array[currentIndex]=tempArray[rightIndex];  
                rightIndex++;  
            }  
            currentIndex++;  
        }  
  
        // Copy the remaining elements of the left half (if any)  
        while (leftIndex<=mid)   
        {  
            array[currentIndex]=tempArray[leftIndex];  
            leftIndex++;  
            currentIndex++;  
        }  
  
        // Copy the remaining elements of the right half (if any)  
        while (rightIndex <= high)   
        {  
            array[currentIndex] = tempArray[rightIndex];  
            rightIndex++;  
            currentIndex++;  
        }  
    }  
  
    public static void main(String[] args) {  
        int[] array = {9,2,5,1,7,4,8,3,6,11,15,12,13,10,14};  
        MultithreadedMergeSort sorter=new MultithreadedMergeSort();  
        sorter.sort(array);  
        System.out.println(Arrays.toString(array));  
    }  
}  

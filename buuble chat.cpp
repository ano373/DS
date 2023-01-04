void bubbleSort(int arr[], int n)
{
    // flag to track if there were any swaps in the current pass
    bool swapped = true;

    // loop until no swaps are made in a pass
    while (swapped)
    {
        // set flag to false
        swapped = false;

        // perform bubble sort
        for (int i = 0; i < n - 1; i++)
        {
            // if two adjacent elements are out of order, swap them
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                // set flag to true as a swap was made
                swapped = true;
            }
        }
    }
}

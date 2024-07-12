
//since we can take half of the things as well , ike in fraction 
//so its better that we calculate weight/value ratio



class Solution {
  public:
    bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
     }
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);

    int curWeight = 0;
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            // Take the whole item
            curWeight += arr[i].weight;
            totalValue += arr[i].value;
        } else {
            // Take a fraction of the item
            int remainingCapacity = W - curWeight;
            totalValue += (arr[i].value / (double) arr[i].weight) * remainingCapacity;
            break; // No more items can be added
        }
    }

    return totalValue;
        
    }
};
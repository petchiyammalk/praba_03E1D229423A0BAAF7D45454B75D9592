   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>

   int* linear_search_product(const char** products, int product_count, const char* target_product, int* result_count) {
       int* indices = (int*)malloc(sizeof(int) * product_count);
       int count = 0;

       for (int i = 0; i < product_count; i++) {
           if (strcmp(products[i], target_product) == 0) {
               indices[count] = i;
               count++;
           }
       }

       *result_count = count;
       return indices;
   }

   int main() {
       const char* products[] = {"Apple", "Banana", "Orange", "Apple", "Mango", "Apple"};
       const char* target_product = "Apple";
       int product_count = 6;

       int result_count;
       int* result = linear_search_product(products, product_count, target_product, &result_count);

       if (result_count > 0) {
           printf("%s found at indices:", target_product);
           for (int i = 0; i < result_count; i++) {
               printf(" %d", result[i]);
           }
           printf("\n");
       } else {
           printf("%s not found in the list.\n", target_product);
       }

       free(result); // Don't forget to free the dynamically allocated array.

       return 0;
   }

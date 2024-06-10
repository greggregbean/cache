#include "fr_cache.hpp"

int main(int argc, char* argv[]) 
{
  int num;
  int capacity
  int x;

  if (argv[1] != nullptr) 
  {
    if (strcmp(argv[1], "detailed") == 0) 
    {
      std::cout << "Enter capacity of cache and  number of elements:" << std::endl;

      std::cin >> capacity;
      while (capacity <= 0) 
      { 
        std::cout << "Wrong capacity!!!" << std::endl;
        std::cin >> capacity
      }

      std::cin >> num;
      while(num <= 0) 
      {
        std::cout << "Wrong num of elements!!!" << std::endl;
        std::cin >> num;
      }
      
      fr_cache cache_mem (capacity);
      cache_mem.dump();
      cache_mem.graphdump();

      
      for(int i = 0; i < num; ++i) 
      {
        std::cout << i <<") Left " << num - i << " numbers. Enter a number: " << std::endl;
        std::cin >> x;
        cache_mem.cache(x);
        cache_mem.dump();
        cache_mem.graphdump();
      }

      std::cout << "Total num of hits: ";
      cache_mem.show_hits();
    }

    if(strcmp(argv[1], "test") == 0)
    {
      testing();
    }
  }

  else 
  {
    std::cin >> capacity;
    std::cin >> num;

    fr_cache cache_mem (capacity);

    for(int i = 0; i < num; ++i) 
    {
      std::cin >> x;
      cache_mem.cache (x);
    } 

    cache_mem.show_hits();
  }
}

#include <iostream>
#include <random>
#include <map>

int main()
{
  std::mt19937 rng_engine(42);

  std::poisson_distribution<int> distribution(1.0);

  std::map<int,int> tally;

  const int n_trials{100000};

  for (int i=0; i!=n_trials; ++i)
  {
    const int x = distribution(rng_engine);
    const auto iter = tally.find(x);
    if (iter == std::end(tally)) { tally.insert(std::make_pair(x, 0)); }
    else { ++(*iter).second; }
  }
  for (const auto& p: tally)
  {
    std::cout << p.first << ": "
      << (100.0 * p.second / n_trials) << "%\n";
  }
}

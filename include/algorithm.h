#pragma once
#include <cstddef>
#include <vector>
#include <iostream>
namespace my
{
    class Stats
    {
    public:
        size_t comparison_count = 0;
        size_t copy_count = 0;
        Stats operator+(const Stats &other) const
        {
            Stats result;
            result.comparison_count = comparison_count + other.comparison_count;
            result.copy_count = copy_count + other.copy_count;
            return result;
        }
    };
    void print_stats(Stats statist)
    {
        std::cout << statist.comparison_count << std::endl;
        std::cout << statist.copy_count << std::endl;
    }
    template <typename Iterator>
    Stats bubbleSort(Iterator begin, Iterator end)
    {
        Stats stats;
        bool swapped; // добавил для оптимизации.
        Iterator lastUnsorted = end;
        for (Iterator i = begin; i != lastUnsorted - 1; ++i)
        {
            swapped = false;
            for (Iterator j = begin; j != lastUnsorted - 1; ++j)
            {
                stats.comparison_count++;
                if (*j > *(j + 1))
                {
                    std::iter_swap(j, j + 1);
                    stats.copy_count++;
                    swapped = true;
                }
            }
            if (!swapped)
                break;
            --lastUnsorted;
        }
        return stats;
    }

    template <typename Iterator>
    Stats combSort(Iterator begin, Iterator end)
    {
        int n = std::distance(begin, end);
        int gap = n;
        bool swapped = true;
        Stats stats;
        while (gap > 1 || swapped)
        {
            gap = (gap * 10) / 13;
            if (gap < 1)
            {
                gap = 1;
            }
            Iterator i = begin;
            swapped = false;
            while (std::distance(i, end) > gap)
            {
                stats.comparison_count++; // Comparison arr[i] > arr[i + gap]
                if (*i > *(i + gap))
                {
                    std::iter_swap(i, i + gap);
                    stats.copy_count += 3; // 2 swaps + 1 copy
                    swapped = true;
                }
                i++;
            }
        }
        return stats;
    }

    template <typename Iterator>
    Stats Shell_sort(Iterator begin, Iterator end)
    {
        Stats s;
        int n = std::distance(begin, end);
        int gap = n / 2;
        while (gap > 0)
        {
            for (Iterator i = begin + gap; i != end; i++)
            {
                auto tmp = *i;
                Iterator j = i;
                while (j >= begin + gap)
                {
                    s.comparison_count++; // Увеличиваем счетчик сравнений
                    if (*(j - gap) > tmp)
                    {
                        *j = *(j - gap);
                        j -= gap;
                        s.copy_count++;
                    }
                    else
                    {
                        break;
                    }
                }
                *j = tmp;
                s.copy_count++;
            }
            gap /= 2;
        }
        return s;
    }
} // namespace my

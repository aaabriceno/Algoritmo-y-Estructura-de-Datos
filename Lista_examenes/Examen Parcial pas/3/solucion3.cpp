/*Considere el array A, En este array se debe detectar el numero mas cercano
 al promedio de todos los numeros. Este proceso debe ser realizado de tal forma
 que 8 threas funcionen al mismo tiempo en lo posible, en la mayor parte del
 tiempo del programa*/

#include <cmath>
#include <iostream>
#include <limits>
#include <thread>
#include <vector>

const int ARRAY_SIZE = 320;
const int NUM_THREADS = 8;

int A[ARRAY_SIZE] = {
    461, 29,  816, 144, 936, 497, 841, 269, 572, 628, 334, 856, 608, 82,  377,
    344, 624, 830, 675, 273, 411, 191, 583, 881, 949, 498, 844, 787, 531, 908,
    759, 570, 789, 408, 558, 23,  15,  651, 212, 414, 688, 104, 757, 378, 583,
    901, 524, 920, 177, 916, 290, 615, 310, 838, 485, 254, 244, 435, 76,  120,
    313, 781, 616, 544, 327, 950, 292, 625, 798, 565, 470, 802, 808, 626, 386,
    498, 67,  268, 123, 165, 263, 427, 965, 926, 373, 914, 535, 413, 943, 80,
    867, 575, 721, 58,  717, 977, 229, 568, 957, 553, 973, 394, 860, 881, 55,
    948, 452, 765, 885, 780, 868, 344, 519, 498, 832, 991, 934, 330, 968, 978,
    197, 471, 625, 266, 44,  452, 315, 803, 878, 965, 632, 393, 570, 2,   777,
    539, 708, 692, 374, 679, 175, 918, 320, 861, 998, 659, 832, 218, 435, 11,
    670, 603, 171, 23,  772, 303, 309, 776, 182, 97,  583, 658, 192, 805, 816,
    392, 83,  105, 221, 182, 722, 599, 556, 292, 526, 68,  504, 480, 999, 361,
    914, 955, 117, 610, 674, 987, 332, 334, 81,  807, 858, 510, 532, 247, 209,
    880, 242, 379, 663, 609, 485, 521, 438, 904, 546, 126, 891, 341, 158, 468,
    980, 491, 731, 529, 554, 862, 52,  155, 776, 325, 501, 401, 143, 969, 990,
    933, 104, 729, 36,  521, 232, 284, 337, 933, 293, 408, 234, 0,   300, 392,
    233, 215, 822, 226, 555, 22,  434, 898, 327, 825, 110, 601, 582, 860, 850,
    613, 752, 294, 553, 340, 654, 291, 400, 321, 325, 339, 614, 16,  195, 838,
    490, 838, 218, 788, 995, 198, 594, 450, 99,  313, 577, 0,   217, 127, 755,
    540, 798, 990, 838, 300, 140, 672, 674, 507, 977, 873, 722, 191, 239, 641,
    661, 148, 675, 17,  155, 378, 671, 780, 72,  603, 718, 385, 584, 854, 449,
    51,  659, 723, 61,  498};

double calculateAverage(const int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }
  return static_cast<double>(sum) / size;
}

int findClosestToAverage(const int *arr, int size, double average) {
  int closest = arr[0];
  double minDiff = std::abs(arr[0] - average);

  for (int i = 1; i < size; ++i) {
    double diff = std::abs(arr[i] - average);
    if (diff < minDiff) {
      minDiff = diff;
      closest = arr[i];
    }
  }
  return closest;
}

void findClosestInSegment(const int *arr, int start, int end, double average,
                          int &closest) {
  int localClosest = arr[start];
  double minDiff = std::abs(arr[start] - average);

  for (int i = start + 1; i < end; ++i) {
    double diff = std::abs(arr[i] - average);
    if (diff < minDiff) {
      minDiff = diff;
      localClosest = arr[i];
    }
  }

  // Update the closest value if this segment contains a closer number
  if (std::abs(localClosest - average) < std::abs(closest - average)) {
    closest = localClosest;
  }
}

void findClosestToAverageParallel(const int *arr, int size, double average,
                                  int &closest) {
  int segmentSize = size / NUM_THREADS;
  std::vector<std::thread> threads;

  for (int i = 0; i < NUM_THREADS; ++i) {
    int start = i * segmentSize;
    int end = (i == NUM_THREADS - 1) ? size : (i + 1) * segmentSize;
    threads.emplace_back(findClosestInSegment, arr, start, end, average,
                         std::ref(closest));
  }

  for (auto &t : threads) {
    t.join();
  }
}

int main() {
  double average = calculateAverage(A, ARRAY_SIZE);
  int closest = A[0]; // Initialize with the first element
  findClosestToAverageParallel(A, ARRAY_SIZE, average, closest);

  std::cout << "El número más cercano al promedio (" << average
            << ") es: " << closest << std::endl;

  return 0;
}
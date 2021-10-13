/*
 * 	efficiency_measure.h
 *
 *  Created on: Oct 9, 2021
 *
 *  Author: Thuan Bach
 *
 * This module is used to measure the efficiency of the sort method implemented in the library <algorithm>
 *
 */

#ifndef EFFICIENCY_MEASUREMENT_H_
#define EFFICIENCY_MEASUREMENT_H_

/**
 *
 *
 * Measure the efficiency of the sort method implemented in the library <algorithm>.
 * The method will measure the execution time of the sort method with 3 kinds of array length: 10,000; 100,000 and 1,000,000.
 * For each kind of array size, it will calculate the execution time for 10 arrays. And for each array, it will test with 3 kinds
 * of array order: Random order, ascending order, and reverse order. The execution time will be measured in millisecond (ms).
 */
void measure_sorting_efficiency();



#endif /* EFFICIENCY_MEASUREMENT_H_ */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>

int main() {
	int sampleSize;
	float entry;
	
	// size of sample
	printf("Enter your sample size: ");
	scanf("%d", &sampleSize);
	float entries[sampleSize];
	float mean(float entries[], int sampleSize);
	float median(float entries[], int sampleSize);
	float range(float entries[], int sampleSize);
	float variance(float entries[], int sampleSize);
	float sd(float entries[], int sampleSize);
	float Q1(float entries[], int sampleSize);
	float Q3(float entries[], int sampleSize);
	float iqr(float entries[], int sampleSize);
	
	// input values 
	for (int i = 0; i < sampleSize; i++) {
		printf("Enter a value: ");
		scanf("%f", &entry);
		entries[i] = entry;
	}
	
	// sort in ascending order for convenience in calculating some stats
	int tmpMin;
	for (int i = 0; i < sampleSize; i++) {   
		// move numbers in order  
		for (int j = i + 1; j < sampleSize; j++) {     
			if(entries[i] > entries[j]) {    
				tmpMin = entries[i];    
			        entries[i] = entries[j];    
			        entries[j] = tmpMin;    
			   }     
		}     
    	}
    	float quartiles[5] = {entries[0], Q1(entries, sampleSize), median(entries, 		sampleSize), Q3(entries, sampleSize), entries[sampleSize - 1]};
    	
    	printf("Mean: %f\n", mean(entries, sampleSize));
    	printf("Median: %f\n", median(entries, sampleSize));
    	printf("Range: %f\n", range(entries, sampleSize));
    	printf("Variance: %f\n", variance(entries, sampleSize));
    	printf("Standard deviation: %f\n", sd(entries, sampleSize));
    	printf("Quartiles: ");
    	// print quartiles
    	for (int i = 0; i < 5; i++) {
    		// correct punctuation
    		if (i == 4) {
    			printf("%f", quartiles[i]);
    		}
    		else {
    			printf("%f, ", quartiles[i]);
    		}
    	}
    	printf("\n");
    	printf("Inter-quartile range: %f\n", iqr(entries, sampleSize));
    	outliers(entries, sampleSize);

	return 0;
}

// calculate mean
float mean(float entries[], int sampleSize) {
	float total = 0;
	float mean;
	
	// gather total cumulative value
	for (int i = 0; i < sampleSize; i++) {
		total += entries[i];
	}
	mean = total / sampleSize;
	
	return mean;
}

// calculate median
float median(float entries[], int sampleSize) {
	float median;
	
	// middlemost value
	if (sampleSize % 2 == 0) {
		median = (entries[sampleSize / 2] + entries[sampleSize / 2 - 1]) / 2;
	}
	else {
		median = entries[(sampleSize - 1) / 2];
	}
	
	return median;
}

// calculate range
float range(float entries[], int sampleSize) {
	float range = entries[sampleSize - 1] - entries[0];
	
	return range;
}

// calculate variance
float variance(float entries[], int sampleSize) {
	float mean(float entries[], int sampleSize);
	float total = 0;
	float variance;
	
	// sum of data
	for (int i = 0; i < sampleSize; i++) {
		total += (entries[i] - mean(entries, sampleSize)) * (entries[i] - 			mean(entries, sampleSize));
	}
	
	variance = total / sampleSize;
	
	return variance;
}

// calculate standard deviation
float sd(float entries[], int sampleSize) {
	float variance(float entries[], int sampleSize);
	float sd = sqrt(variance(entries, sampleSize));
	
	return sd;
}

// calculate first quartiles
float Q1(float entries[], int sampleSize) {
	float q1;
	
	// calculate median of first half
	if (sampleSize % 2 == 0) {
		if ((sampleSize / 2) % 2 == 0) {
			q1 = (entries[0] + entries[sampleSize / 2 - 1]) / 2;
		}
		else {
			q1 = entries[(sampleSize / 2 - 1) / 2];
		}
	}
	else {
		if ((sampleSize - 1) / 2 % 2 == 0) {
			q1 = (entries[(sampleSize - 1) / 4] + entries[(sampleSize - 				1) / 4 - 1]) / 2;
		}
		else {
			q1 = entries[(sampleSize - 1) / 2 - 1];
		}
	}
	
	return q1;
}

//calculate third quartile
float Q3(float entries[], int sampleSize) {
	float q3;
	
	// calculate madian of second half
	if (sampleSize % 2 == 0) {
		if ((sampleSize / 2) % 2 == 0) {
			q3 = (entries[sampleSize / 2] + entries[sampleSize - 1]) / 				2;
		}
		else {
			q3 = (entries[sampleSize / 2] + entries[sampleSize / 2 + 			(sampleSize / 2 - 1) / 2]) / 2;
		}
	}
	else {
		if ((sampleSize - 1) / 2 % 2 == 0) {
			q3 = (entries[(sampleSize - 1) * 3 / 4] + 			entries[(sampleSize - 1) * 3 / 4 + 1]) / 2;
		}
		else {
			q3 = entries[(sampleSize + 1) / 2 + 1];
		}
	}
	
	return q3;
}

// calculate inter-quartile range
float iqr(float entries[], int sampleSize) {
	float Q1(float entries[], int sampleSize);
	float Q3(float entries[], int sampleSize);
	float iqr = Q3(entries, sampleSize) - Q1(entries, sampleSize);
	
	return iqr;
}

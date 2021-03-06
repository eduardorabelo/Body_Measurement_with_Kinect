/****************************************************************************
* 
*  Computer Vision, Fall 2011
*  New York University
*
*  Created by Otavio Braga (obraga@cs.nyu.edu)
*
****************************************************************************/

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <vector>

class histogram
{
    public:
        histogram(double min_value, double max_value, int nbins);

        // Returns the value of a histogram bin
        const double &operator()(unsigned int bin) const;
        double &operator()(unsigned int bin);

        const double & operator[](unsigned int bin) const;
        double & operator[](unsigned int bin);

        void get_range(double *minv, double *maxv) const
        {
            *minv = min_value;
            *maxv = max_value;
        }

        double get_min() const { return min_value; }
        double get_max() const { return max_value; }

        unsigned int get_n_bins() const { return hist.size(); }

        double get_bin_size() const { return binsize; }

        // Increment the count of the bin where v falls into.
        // Insert into the first or last bin if the value is outside
        // the histogram range.
        //
        // !!!!!!!!!! Implement this method !!!!!!!!!!
        //
        void insert_point(double v);

        // Normalize the histogram in order to turn it into a
        // probability distribution
        //
        // !!!!!!!!!! Implement this method !!!!!!!!!!
        //
        void normalize();

        // Clear the histogram by setting all its bins to zero
        void clear();

    private:
        std::vector<double> hist;
        double min_value, max_value;
        double binsize;
};

inline        
histogram::histogram(double min_value, double max_value, int nbins)
    : hist(nbins), min_value(min_value), max_value(max_value)
{
    binsize = (max_value - min_value)/nbins;
    for (int i = 0; i < nbins; i++)
        hist[i] = 0.0;
}
        
inline
double &histogram::operator()(unsigned int bin)
{
    return hist[bin];
};

inline
const double &histogram::operator()(unsigned int bin) const
{
    return hist[bin];
};

inline        
double & histogram::operator[](unsigned int bin)
{
    return hist[bin];
}

inline        
const double & histogram::operator[](unsigned int bin) const
{
    return hist[bin];
}
        
inline
void histogram::insert_point(double v)
{
    // !!!!!!!!!! Implement this method !!!!!!!!!!
    //std::cout << "Warning: histogram::insert_point not implemented!\n";
	if(v != 0){
		int k = v / 50.0;
		if(k < hist.size())
			hist[k] ++;
	}
}

inline
void histogram::normalize()
{
    // !!!!!!!!!! Implement this method !!!!!!!!!!
    //std::cout << "Warning: histogram::normalize not implemented!\n";
	double sum;
	sum = 0.0;
	for(int i=0; i<get_n_bins(); i++){
		sum += hist[i];
	}
	for(int i=0; i<get_n_bins(); i++){
		hist[i] /= sum;
	}
}

inline void histogram::clear()
{
    for (unsigned int i = 0; i < hist.size(); i++)
        hist[i] = 0;
}

inline std::ostream &operator<<(std::ostream &os, const histogram &h)
{
    int N = h.get_n_bins();
    double range_min, range_max;
    
    range_min = h.get_min();
    range_max = range_min + h.get_bin_size();
    int MAX_BARS = 200;
    for (int i = 0; i < N; i++, range_min = range_max, range_max += h.get_bin_size())
    {
        printf("[%8.2f, %8.2f] : %f ", range_min, range_max, h(i));
        int nbars = (int)(h(i)*MAX_BARS);
        for (int j = 0; j < nbars; j++)
            printf("|");
        printf("\n");
    }
    return os;
}

// Create the histogram of a depth map, with the parameters of the provided
// histogram 'hist' created beforehand.
//
//     depthimage: the kinect depth image 
//     npts: the number of pixels in the depth map
//
// If normalize is true, normalize the histogram entries so that they add up
// to one.
//
void compute_histogram(unsigned short *depthimage,
                       int npts,
                       histogram &hist,
                       bool normalize = false);

#endif // HISTOGRAM_H



#include "objects.h"
#include "synapses_classes.h"
#include "brianlib/clocks.h"
#include "brianlib/dynamic_array.h"
#include "brianlib/stdint_compat.h"
#include "network.h"
#include "randomkit.h"
#include<vector>
#include<iostream>
#include<fstream>

namespace brian {

std::vector< rk_state* > _mersenne_twister_states;

//////////////// networks /////////////////

//////////////// arrays ///////////////////
double * _array_defaultclock_dt;
const int _num__array_defaultclock_dt = 1;
double * _array_defaultclock_t;
const int _num__array_defaultclock_t = 1;
int64_t * _array_defaultclock_timestep;
const int _num__array_defaultclock_timestep = 1;
int32_t * _array_neurongroup_1__spikespace;
const int _num__array_neurongroup_1__spikespace = 101;
int32_t * _array_neurongroup_1_i;
const int _num__array_neurongroup_1_i = 100;
double * _array_neurongroup_1_lastspike;
const int _num__array_neurongroup_1_lastspike = 100;
char * _array_neurongroup_1_not_refractory;
const int _num__array_neurongroup_1_not_refractory = 100;
double * _array_neurongroup_1_v;
const int _num__array_neurongroup_1_v = 100;
double * _array_neurongroup_1_v0;
const int _num__array_neurongroup_1_v0 = 100;
int32_t * _array_spikemonitor_1__source_idx;
const int _num__array_spikemonitor_1__source_idx = 100;
int32_t * _array_spikemonitor_1_count;
const int _num__array_spikemonitor_1_count = 100;
int32_t * _array_spikemonitor_1_N;
const int _num__array_spikemonitor_1_N = 1;

//////////////// dynamic arrays 1d /////////
std::vector<int32_t> _dynamic_array_spikemonitor_1_i;
std::vector<double> _dynamic_array_spikemonitor_1_t;

//////////////// dynamic arrays 2d /////////

/////////////// static arrays /////////////

//////////////// synapses /////////////////

//////////////// clocks ///////////////////
Clock defaultclock;  // attributes will be set in run.cpp

}

void _init_arrays()
{
	using namespace brian;

    // Arrays initialized to 0
	_array_defaultclock_dt = new double[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_dt[i] = 0;

	_array_defaultclock_t = new double[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_t[i] = 0;

	_array_defaultclock_timestep = new int64_t[1];
    
	for(int i=0; i<1; i++) _array_defaultclock_timestep[i] = 0;

	_array_neurongroup_1__spikespace = new int32_t[101];
    
	for(int i=0; i<101; i++) _array_neurongroup_1__spikespace[i] = 0;

	_array_neurongroup_1_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_i[i] = 0;

	_array_neurongroup_1_lastspike = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_lastspike[i] = 0;

	_array_neurongroup_1_not_refractory = new char[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_not_refractory[i] = 0;

	_array_neurongroup_1_v = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_v[i] = 0;

	_array_neurongroup_1_v0 = new double[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_v0[i] = 0;

	_array_spikemonitor_1__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_1__source_idx[i] = 0;

	_array_spikemonitor_1_count = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_1_count[i] = 0;

	_array_spikemonitor_1_N = new int32_t[1];
    
	for(int i=0; i<1; i++) _array_spikemonitor_1_N[i] = 0;


	// Arrays initialized to an "arange"
	_array_neurongroup_1_i = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_neurongroup_1_i[i] = 0 + i;

	_array_spikemonitor_1__source_idx = new int32_t[100];
    
	for(int i=0; i<100; i++) _array_spikemonitor_1__source_idx[i] = 0 + i;


	// static arrays

	// Random number generator states
	for (int i=0; i<1; i++)
	    _mersenne_twister_states.push_back(new rk_state());
}

void _load_arrays()
{
	using namespace brian;

}

void _write_arrays()
{
	using namespace brian;

	ofstream outfile__array_defaultclock_dt;
	outfile__array_defaultclock_dt.open("results\\_array_defaultclock_dt_2713660315933898335", ios::binary | ios::out);
	if(outfile__array_defaultclock_dt.is_open())
	{
		outfile__array_defaultclock_dt.write(reinterpret_cast<char*>(_array_defaultclock_dt), 1*sizeof(_array_defaultclock_dt[0]));
		outfile__array_defaultclock_dt.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_dt." << endl;
	}
	ofstream outfile__array_defaultclock_t;
	outfile__array_defaultclock_t.open("results\\_array_defaultclock_t_-1107759585924734809", ios::binary | ios::out);
	if(outfile__array_defaultclock_t.is_open())
	{
		outfile__array_defaultclock_t.write(reinterpret_cast<char*>(_array_defaultclock_t), 1*sizeof(_array_defaultclock_t[0]));
		outfile__array_defaultclock_t.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_t." << endl;
	}
	ofstream outfile__array_defaultclock_timestep;
	outfile__array_defaultclock_timestep.open("results\\_array_defaultclock_timestep_8182616447733045623", ios::binary | ios::out);
	if(outfile__array_defaultclock_timestep.is_open())
	{
		outfile__array_defaultclock_timestep.write(reinterpret_cast<char*>(_array_defaultclock_timestep), 1*sizeof(_array_defaultclock_timestep[0]));
		outfile__array_defaultclock_timestep.close();
	} else
	{
		std::cout << "Error writing output file for _array_defaultclock_timestep." << endl;
	}
	ofstream outfile__array_neurongroup_1__spikespace;
	outfile__array_neurongroup_1__spikespace.open("results\\_array_neurongroup_1__spikespace_1832437356009395787", ios::binary | ios::out);
	if(outfile__array_neurongroup_1__spikespace.is_open())
	{
		outfile__array_neurongroup_1__spikespace.write(reinterpret_cast<char*>(_array_neurongroup_1__spikespace), 101*sizeof(_array_neurongroup_1__spikespace[0]));
		outfile__array_neurongroup_1__spikespace.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1__spikespace." << endl;
	}
	ofstream outfile__array_neurongroup_1_i;
	outfile__array_neurongroup_1_i.open("results\\_array_neurongroup_1_i_484747398381110773", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_i.is_open())
	{
		outfile__array_neurongroup_1_i.write(reinterpret_cast<char*>(_array_neurongroup_1_i), 100*sizeof(_array_neurongroup_1_i[0]));
		outfile__array_neurongroup_1_i.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_i." << endl;
	}
	ofstream outfile__array_neurongroup_1_lastspike;
	outfile__array_neurongroup_1_lastspike.open("results\\_array_neurongroup_1_lastspike_4730117913014123418", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_lastspike.is_open())
	{
		outfile__array_neurongroup_1_lastspike.write(reinterpret_cast<char*>(_array_neurongroup_1_lastspike), 100*sizeof(_array_neurongroup_1_lastspike[0]));
		outfile__array_neurongroup_1_lastspike.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_lastspike." << endl;
	}
	ofstream outfile__array_neurongroup_1_not_refractory;
	outfile__array_neurongroup_1_not_refractory.open("results\\_array_neurongroup_1_not_refractory_6634595067739952522", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_not_refractory.is_open())
	{
		outfile__array_neurongroup_1_not_refractory.write(reinterpret_cast<char*>(_array_neurongroup_1_not_refractory), 100*sizeof(_array_neurongroup_1_not_refractory[0]));
		outfile__array_neurongroup_1_not_refractory.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_not_refractory." << endl;
	}
	ofstream outfile__array_neurongroup_1_v;
	outfile__array_neurongroup_1_v.open("results\\_array_neurongroup_1_v_432766604249813838", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_v.is_open())
	{
		outfile__array_neurongroup_1_v.write(reinterpret_cast<char*>(_array_neurongroup_1_v), 100*sizeof(_array_neurongroup_1_v[0]));
		outfile__array_neurongroup_1_v.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_v." << endl;
	}
	ofstream outfile__array_neurongroup_1_v0;
	outfile__array_neurongroup_1_v0.open("results\\_array_neurongroup_1_v0_-3146930195140020378", ios::binary | ios::out);
	if(outfile__array_neurongroup_1_v0.is_open())
	{
		outfile__array_neurongroup_1_v0.write(reinterpret_cast<char*>(_array_neurongroup_1_v0), 100*sizeof(_array_neurongroup_1_v0[0]));
		outfile__array_neurongroup_1_v0.close();
	} else
	{
		std::cout << "Error writing output file for _array_neurongroup_1_v0." << endl;
	}
	ofstream outfile__array_spikemonitor_1__source_idx;
	outfile__array_spikemonitor_1__source_idx.open("results\\_array_spikemonitor_1__source_idx_-3163349098684471255", ios::binary | ios::out);
	if(outfile__array_spikemonitor_1__source_idx.is_open())
	{
		outfile__array_spikemonitor_1__source_idx.write(reinterpret_cast<char*>(_array_spikemonitor_1__source_idx), 100*sizeof(_array_spikemonitor_1__source_idx[0]));
		outfile__array_spikemonitor_1__source_idx.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_1__source_idx." << endl;
	}
	ofstream outfile__array_spikemonitor_1_count;
	outfile__array_spikemonitor_1_count.open("results\\_array_spikemonitor_1_count_8214753151228917930", ios::binary | ios::out);
	if(outfile__array_spikemonitor_1_count.is_open())
	{
		outfile__array_spikemonitor_1_count.write(reinterpret_cast<char*>(_array_spikemonitor_1_count), 100*sizeof(_array_spikemonitor_1_count[0]));
		outfile__array_spikemonitor_1_count.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_1_count." << endl;
	}
	ofstream outfile__array_spikemonitor_1_N;
	outfile__array_spikemonitor_1_N.open("results\\_array_spikemonitor_1_N_1310583111216231258", ios::binary | ios::out);
	if(outfile__array_spikemonitor_1_N.is_open())
	{
		outfile__array_spikemonitor_1_N.write(reinterpret_cast<char*>(_array_spikemonitor_1_N), 1*sizeof(_array_spikemonitor_1_N[0]));
		outfile__array_spikemonitor_1_N.close();
	} else
	{
		std::cout << "Error writing output file for _array_spikemonitor_1_N." << endl;
	}

	ofstream outfile__dynamic_array_spikemonitor_1_i;
	outfile__dynamic_array_spikemonitor_1_i.open("results\\_dynamic_array_spikemonitor_1_i_-3590562129111038133", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_1_i.is_open())
	{
        if (! _dynamic_array_spikemonitor_1_i.empty() )
        {
			outfile__dynamic_array_spikemonitor_1_i.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_1_i[0]), _dynamic_array_spikemonitor_1_i.size()*sizeof(_dynamic_array_spikemonitor_1_i[0]));
		    outfile__dynamic_array_spikemonitor_1_i.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_1_i." << endl;
	}
	ofstream outfile__dynamic_array_spikemonitor_1_t;
	outfile__dynamic_array_spikemonitor_1_t.open("results\\_dynamic_array_spikemonitor_1_t_5522647248200964841", ios::binary | ios::out);
	if(outfile__dynamic_array_spikemonitor_1_t.is_open())
	{
        if (! _dynamic_array_spikemonitor_1_t.empty() )
        {
			outfile__dynamic_array_spikemonitor_1_t.write(reinterpret_cast<char*>(&_dynamic_array_spikemonitor_1_t[0]), _dynamic_array_spikemonitor_1_t.size()*sizeof(_dynamic_array_spikemonitor_1_t[0]));
		    outfile__dynamic_array_spikemonitor_1_t.close();
		}
	} else
	{
		std::cout << "Error writing output file for _dynamic_array_spikemonitor_1_t." << endl;
	}

	// Write last run info to disk
	ofstream outfile_last_run_info;
	outfile_last_run_info.open("results/last_run_info.txt", ios::out);
	if(outfile_last_run_info.is_open())
	{
		outfile_last_run_info << (Network::_last_run_time) << " " << (Network::_last_run_completed_fraction) << std::endl;
		outfile_last_run_info.close();
	} else
	{
	    std::cout << "Error writing last run info to file." << std::endl;
	}
}

void _dealloc_arrays()
{
	using namespace brian;


	// static arrays
}


#ifndef INCLUDE_PARAMS_H_
#define INCLUDE_PARAMS_H_

#include <map>

#include "cgs.h"
#include "pid.h"

typedef std::map<PID, double> List;

class ParticleList {
private:
	List list;

public:
	ParticleList() {
		insert(H1, 0.);
		insert(C12, 0.);
		insert(N14, 0.);
		insert(O16, 0.);
		insert(B10, 0.);
		insert(B11, 0.);
		insert(Fe56, 0.);
		insert(Ne20, 0.);
		insert(Mg24, 0.);
		insert(Si28, 0.);
	}

	const List& get_list() {
		return list;
	}

	virtual ~ParticleList();
	bool insert(const PID& key, const double& value);
	void set_abundance(const PID& key, const double& value);
	void print();
};

class Params {
private:
	double _H = 4. * cgs::kpc;
	double _T_min = 1.0 * cgs::GeV;
	double _T_max = 10. * cgs::TeV;
	double _mu = 2.7 * cgs::mgram / cgs::cm2;
	double _v_A = 10. * cgs::km / cgs::sec;
	double _R_b = 312. * cgs::GeV;
	double _delta = 0.62;
	double _ddelta = 0.15;
	double _smoothness = 0.04;
	double _D_0 = 1.8e28 * cgs::cm2 / cgs::sec;
	double _H_slope = 4.25;
	double _nuclei_slope = 4.25;
	double _modulation_potential = 0.7 * cgs::GeV;
	size_t _T_size = 100;

public:
	Params() {
	}

	void set_H(const double& _H) {
		this->_H = _H;
	}

	void set_D0(const double& _D_0) {
		this->_D_0 = _D_0;
	}

	virtual ~Params();
	void print();

	const double& T_min = _T_min;
	const double& T_max = _T_max;
	const double& H = _H;
	const double& mu = _mu;
	const double& v_A = _v_A;
	const double& R_b = _R_b;
	const double& delta = _delta;
	const double& ddelta = _ddelta;
	const double& smoothness = _smoothness;
	const double& D_0 = _D_0;
	const double& H_slope = _H_slope;
	const double& nuclei_slope = _nuclei_slope;
	const double& modulation_potential = _modulation_potential;
	const size_t& T_size = _T_size;

//	Param<double> h_gas = Param<double>(150 * pc);
//	Param<double> potential = Param<double>(100 * MeV);
//	Param<int> E_size = Param<int>(6 * 32);
//	double B_0 = muG;
//	Param<double> v_A = Param<double>(
//			B_0 / std::sqrt(vacuum_permeability * proton_mass * ion_number_density));
//	Param<std::string> out_name = Param < std::string > ("test");
};

#endif /* INCLUDE_PARAMS_H_ */

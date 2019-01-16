#include "output.h"
#include "utilities.h"

OutputManager::OutputManager(const LogAxis& T, const std::vector<Particle>& particles) :
		_T(T), _particles(particles) {
}

OutputManager::~OutputManager() {
}

void OutputManager::dump_spectra(double R_min, double R_max, size_t R_size) const {
	auto ptr_H1 = find(_particles.begin(), _particles.end(), Particle(H1, 0));
	auto ptr_C12 = find(_particles.begin(), _particles.end(), Particle(C12, 0));
	auto ptr_O16 = find(_particles.begin(), _particles.end(), Particle(O16, 0));
	LogAxis R(R_min, R_max, R_size);
	std::ofstream outfile("primary_spectra.txt");
	outfile << std::scientific;
	double units = 1. / (cgs::GeV * pow2(cgs::meter) * cgs::sec);
	for (size_t i = 0; i < R_size; ++i) {
		double R_ = R.at(i);
		outfile << R_ / cgs::GeV << "\t";
		outfile << ptr_H1->get_I_R_TOA(R_, 0.7 * cgs::GeV) / units << "\t";
		outfile << ptr_C12->get_I_R_TOA(R_, 0.7 * cgs::GeV) / units << "\t";
		outfile << ptr_O16->get_I_R_TOA(R_, 0.7 * cgs::GeV) / units << "\t";
		outfile << "\n";
	}
	outfile.close();
}
/* 
 * Es el objeto que relaciona la preferencia del profesor por los diferentes
 * horarios
 *
 * */
#ifndef T_COST_HORA_PROF_H
#define T_COST_HORA_PROF_H
#include <string>
class TCostHoraProf {
	private:
		const char *pchrHorario;
		int intCoste;
	public:
		TCostHoraProf(const char*, int);
		TCostHoraProf(const std::string, int);
		int GetCoste(void);
		const char *GetHorario(void);
};

#endif

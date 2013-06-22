/* 
 * Es el objeto que relaciona la preferencia del profesor por un horario
 *
 * */
#ifndef T_COST_HORA_PROF_H
#define T_COST_HORA_PROF_H
#include <string>
class TCostHoraProf {
	private:
		std::string strHorario;
		int intCoste;
	public:
		TCostHoraProf(const char*, int);
		TCostHoraProf(std::string, int);
		int GetCoste(void);
		std::string GetHorario(void);
};

#endif

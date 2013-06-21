#ifndef DB_HANDLER_H
#define DB_HANDLER_H

class CDBHandler {
	private:
		sqlite3 *db;
	public:
		CDBHandler(char *pfile);
		
}

#endif

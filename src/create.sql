CREATE TABLE profesor (
	id INTEGER PRIMARY KEY,
	nombre TEXT NOT NULL
);

CREATE TABLE asignatura (
	id INTEGER PRIMARY KEY,
	nombre TEXT NOT NULL
);

CREATE TABLE sala (
	id INTEGER PRIMARY KEY,
	nombre TEXT NOT NULL
);

CREATE TABLE horario (
	id INTEGER PRIMARY KEY,
	dia TEXT NOT NULL,
	bloque_in INTEGER NOT NULL,
	bloque_fin INTEGER
);

CREATE TABLE asig_prof (
	id INTEGER PRIMARY KEY,
	profesor_id INTEGER,
	asignatura_id INTEGER,
	FOREIGN KEY(profesor_id) REFERENCES profesor(id),
	FOREIGN KEY(asignatura_id) REFERENCES asignatura(id)
);

CREATE TABLE sala_horario (
	id INTEGER PRIMARY KEY,
	horario_id INTEGER,
	sala_id INTEGER,
	FOREIGN KEY(horario_id) REFERENCES horario(id),
	FOREIGN KEY(sala_id) REFERENCES sala(id)
);

CREATE TABLE cost_hora_asig_prof (
	id INTEGER PRIMARY KEY,
	coste TEXT NOT NULL,
	asig_prof_id INTEGER,
	horario_id INTEGER,
	FOREIGN KEY(asig_prof_id) REFERENCES asig_prof(id),
	FOREIGN KEY(horario_id) REFERENCES horario(id)
);


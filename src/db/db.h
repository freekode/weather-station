#include <Arduino.h>
#include <stdint.h>
#include "../config.h"

class DbEntry {
	public:
		uint32_t timestamp;
		float temperature;
		float temperature1;
		int humidity;
		float pressure;
		DbEntry() {};
		DbEntry(
			uint32_t timestamp,
			float temperature,
			float temperature1,
			int humidity,
			float pressure):
				timestamp(timestamp),
				temperature(temperature),
				temperature1(temperature1),
				humidity(humidity),
				pressure(pressure) {};
		String toString();
};

class Database {
	int nextDbIndex = 0;
	DbEntry storage[IN_MEMORY_DB_SIZE];
	static Database *s_instance;
	public:
		static Database *getInstance() {
				if (!s_instance) {
					s_instance = new Database;
				}

				return s_instance;
		};
		DbEntry last();
		DbEntry* all();
		void add(DbEntry newEntry);
};

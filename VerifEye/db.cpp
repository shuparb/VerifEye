#include "db.h"

verifEye::Database::Database()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(QString::fromStdString("./main.db"));
	if (openDb())
		connected = true;

}

verifEye::Database::Database(const std::string dbname)
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(QString::fromStdString(dbname));
	if (openDb())
		connected = true;

}

bool verifEye::Database::openDb()
{
	if (db.open())
		return true;
	return false;
}

bool verifEye::Database::closeDb()
{
	db.close();
	return true;
}

QString verifEye::Database::getSingleValueFromQuery(QSqlQuery query)
{
	while (query.next()) {
		return query.value(0).toString();
	}
	return QString();
}

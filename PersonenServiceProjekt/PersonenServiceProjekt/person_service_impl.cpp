#include "pch.h"
#include "person_service_impl.h"
#include "personen_service_exception.h"
#include "repository_exception.h"
person_service_impl::person_service_impl(person_repository& repo):repo(repo)
{
	
}

void person_service_impl::speichern(person &p)
{
	try {
		if (p.GetVorname().length() < 2)
			throw personen_service_exception("Vorname muss min. 2 Zeichen enthalten.");

		if (p.GetNachname().length() < 2)
			throw personen_service_exception("Nachname muss min. 2 Zeichen enthalten.");

		if (p.GetVorname() == "Attila")
			throw personen_service_exception("Antipath.");

		repo.save(p);
		
		
	} catch (repository_exception &ex)
	{
		throw personen_service_exception("Service nicht verfügbar");
	}
	
	
}

std::optional<person> person_service_impl::findePersonMitId(std::string id)
{
	try {
		return  repo.find_by_id(id);
	} catch (repository_exception &ex)
	{
		return std::nullopt;
	}
}

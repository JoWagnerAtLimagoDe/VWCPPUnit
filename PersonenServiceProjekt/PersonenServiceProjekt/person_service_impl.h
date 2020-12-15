#pragma once

#include <string>
#include "PersonRepository.h"
#include "Person.h"
#include <optional>

class person_service_impl
{

private:
	person_repository &repo;
public:

	person_service_impl(person_repository& repo) ;
	/*
	 * 1. vorname min 2 Zeichen (evtl. nullprüfung) -> person_service_exception
	 * 2. nachname soll min 2 Zeichen (evtl. nullprüfung) -> person_service_exception
	 *
	 * 3. vorname darf nicht Attila sein -> person_service_exception
	 *
	 * 4. Exception im darunter liegenden Layer -> -> person_service_exception
	 * 
	 */
	void speichern(person &p) ;

	/*
	 * Kein Treffer -> RepoException => Leeres Optional
	 * Treffer -> Befülltes Optional
	 * 
	 */
	std::optional<person> findePersonMitId(std::string id);
};


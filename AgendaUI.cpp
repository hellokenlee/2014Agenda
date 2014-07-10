// Copyright @2014KenLee
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "AgendaUI.h"
using std::endl;
using std::cout;
using std::cin;
using std::setw;
using std::list;
using std::string;
AgendaUI::AgendaUI() {
	currentUser_ = NULL;
	cout << std::left;
}

void AgendaUI::getOperation(void) {
	string op;
	startAgenda();
	cout << "***************************Agenda v1.1****************************************" << endl;
	cout << "*l   - log in Agenda by user name and password            *     Welcome      *" << endl;
	cout << "*r   - register an Agenda account                         *       To         *" << endl;
	cout << "*q   - quit Agenda                                        *     Agenda       *" << endl;
	cout << "******************************************************************************" << endl;
	cout << "Agenda : ~$ ";
	while (cin >>op,cin.get()) {
		if (op == "credit") {
			cout << "procduced by KenLee@2014 sysu.ss" <<endl;
			cout << "Agenda : ~$ ";
		} else if (currentUser_ == NULL) {
			if (op != "l" && op != "r" && op != "q") {
				cout << "[error] wrong command!" << endl;
				cout << "Agenda : ~$ ";
			} else {
				executeOperation(op);
				if (op == "q")
					return;
			}
		} else {
			if (op == "o" || op == "lu" || op == "cm" || op == "la"
				|| op == "lap" || op == "las" || op == "qm"
				|| op == "qt" || op == "dm" || op == "dc" || op == "da" ||
				op == "fun" || op == "upa" || op == "upe" || op == "uph") {
					executeOperation(op);
			} else {
				cout << "[error] wrong command!"<< endl;
				cout << "Agenda@" << currentUser_->getName() << " : # ";
			}
		}
	}
}
void AgendaUI::startAgenda(void) {
	agendaService_.startAgenda();
}
bool AgendaUI::executeOperation(std::string op) {
	if (op == "l") {
		userLogIn();
		return true;
	}
	if (op == "r") {
		userRegister();
		return true;
	}
	if (op == "q") {
		quitAgenda();
		return true;
	}
	if (op == "dc") {
		deleteUser();
		return true;
	}
	if (op == "lu") {
		listAllUsers();
		return true;
	}
	if (op == "cm") {
		createMeeting();
		return true;
	}
	if (op == "la") {
		listAllMeetings();
		return true;
	}
	if (op == "las") {
		listAllSponsorMeetings();
		return true;
	}
	if (op == "lap") {
		listAllParticipateMeetings();
		return true;
	}
	if (op == "qm") {
		queryMeetingByTitle();
		return true;
	}
	if (op == "qt") {
		queryMeetingByTimeInterval();
		return true;
	}
	if (op == "dm") {
		deleteMeetingByTitle();
		return true;
	}
	if (op == "da") {
		deleteAllMeetings();
		return true;
	}
	if (op == "o") {
		userLogOut();
		return true;
	}
	if (op == "q") {
		quitAgenda();
		return true;
	}
	return false;
}
void AgendaUI::userLogIn(void) {
	string name, password;
	cout << "[log in] [user name] [password]" << endl;
	cout << "[log in] ";
	cin >> name >> password;
	currentUser_ = agendaService_.userLogIn(name, password);
	if (currentUser_ == NULL) {
		cout << "[error] log in fail!" << endl;
		cout << "Agenda : ~$ ";
	} else  {
		list<Meeting> m = agendaService_.listAllMeetings(currentUser_->getName());
		string m1="", m2="", m3="",e="",d1="",d2="",d3="";
		list<Meeting>::iterator it = m.begin();
		if(it!=m.end()){
			m1 = "1.";
			m1 += it->getTitle();
			d1 ="(";
			d1 += Date::dateToString(it->getStartDate());
			d1 += ")";
			it++;
		}
		if(it!=m.end()){
			m2 = "2.";
			m2 += it->getTitle();
			d2 = "(";
			d2 += Date::dateToString(it->getStartDate());
			d2 += ")";
			it++;
		}
		if(it!=m.end()){
			m3 = "3.";
			m3 += it->getTitle();
			d3 = "(";
			d3 += Date::dateToString(it->getStartDate());
			d3 += ")";
			it++;
		}
		if(it!=m.end()){
			e="...";
		}
		cout << "[log in] succeed!" << endl << endl;
		cout << "****************************Agenda v1.1***************************************" << endl;
		cout << "*Actions :                                                *Meetings To Join: *" << endl;
		cout << "*o    - log out Agenda                                    *                  *" << endl;
		cout << "*dc   - delete Agenda account                             *" << setw(18) << m1 << "*" <<endl;
		cout << "*lu   - list all Agenda user                              *" << setw(18) << d1 << "*" <<endl;
		cout << "*cm   - create a meeting                                  *                  *" <<endl;
		cout << "*la   - list all meetings                                 *" << setw(18) << m2 << "*" << endl;
		cout << "*las  - list all sponsor meetings                         *" << setw(18) << d2 << "*" <<endl;
		cout << "*lap  - list all participate meetings                     *                  *" << endl;
		cout << "*qm   - query meeting by title                            *" << setw(18) << m3 << "*" << endl;
		cout << "*qt   - query meeting by time interval                    *" << setw(18) << d3 << "*" <<endl;
		cout << "*dm   - delete meeting by title                           *" << setw(18) << e << "*" << endl;
		cout << "*da   - delete all meeting                                *                  *" << endl;
		cout << "******************************************************************************" << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
	}
}

void AgendaUI::userRegister(void) {
	string name, password, email, phone;
	cout << "[register] [user name] [password] [email] [phone]" << endl;
	cout << "[register] ";
	cin >> name >> password >> email >> phone;
	if (agendaService_.userRegister(name, password, email, phone)) {
		cout << "[register] succeed!" << endl;
		cout << "Agenda : ~$ ";
	} else  {
		cout << "[error] register fail!" << endl;
		cout << "Agenda : ~$ ";
	}
}
void AgendaUI::quitAgenda(void) {
	agendaService_.quitAgenda();
}
void AgendaUI::userLogOut(void) {
	currentUser_ = NULL;
	cout << "****************************Agenda v1.0***************************************" << endl;
	cout << "*l   - log in Agenda by user name and password            *     Welcome      *" << endl;
	cout << "*r   - register an Agenda account                         *       To         *" << endl;
	cout << "*q   - quit Agenda                                        *     Agenda       *" << endl;
	cout << "******************************************************************************" << endl;
	cout << "Agenda : ~$ ";
}
void AgendaUI::deleteUser(void) {
	if (agendaService_.deleteUser(currentUser_->getName(),currentUser_->getPassword())) {
		cout << "[delete agenda account] succeed!" << endl;
		currentUser_ = NULL;
		cout << "****************************Agenda v1.0****************************************" << endl;
		cout << "*l   - log in Agenda by user name and password            *     Welcome      *" << endl;
		cout << "*r   - register an Agenda account                         *       To         *" << endl;
		cout << "*q   - quit Agenda                                        *     Agenda       *" << endl;
		cout << "******************************************************************************" << endl;
		cout << "Agenda : ~$ ";
	} else  {
		cout << "[error] delete agenda account fail!" << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
	}
}
void AgendaUI::listAllUsers(void) {
	cout << "[list all users]" << endl << endl;
	cout << setw(10) << "name" <<setw(20) << "email";
	cout << setw(15) << "phone" << endl;
	list<User>::iterator it;
	list<User> u;
	u = agendaService_.listAllUsers();
	for (it = u.begin(); it != u.end(); it++) {
		cout << setw(10) << it->getName();
		cout << setw(20) << it->getEmail();
		cout << setw(15) << it->getPhone() << endl;
	}
	cout << "Agenda@" << currentUser_->getName() << " : # ";
}
void AgendaUI::createMeeting(void) {
	cout << "[create meeting] [title] [participator] ";
	cout << "[start time(yyyy-mm-dd/hh:mm)] ";
	cout << "[end time(yyyy-mm-dd/hh:mm)] " << endl;
	cout << "[create meetings] ";
	string name, title, participator, sTime, eTime;
	cin >> title >> participator >> sTime >> eTime;
	name = currentUser_->getName();
	if (agendaService_.createMeeting(name, title, participator,
		sTime, eTime)) {
			cout << "[create meeting] succeed!" << endl;
			cout << "Agenda@" << currentUser_->getName() << " : # ";
	} else  {
		cout << "[error] create meeting fail!" << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
	}
}
void AgendaUI::listAllMeetings(void) {
	cout << "[list all meetings]" << endl << endl;
	printMeetings(agendaService_.listAllMeetings(currentUser_->getName()));
	cout << "Agenda@" << currentUser_->getName() << " : # ";
}
void AgendaUI::listAllSponsorMeetings(void) {
	cout << "[list all sponsor meetingd]" << endl << endl;
	printMeetings(agendaService_.listAllSponsorMeetings(
		currentUser_->getName()));
	cout << "Agenda@" << currentUser_->getName() << " : # ";
}
void AgendaUI::listAllParticipateMeetings(void) {
	cout << "[list all participate meetingd]" << endl << endl;
	printMeetings(agendaService_.listAllParticipateMeetings(
		currentUser_->getName()));
	cout << "Agenda@" << currentUser_->getName() << " : # ";
}
void AgendaUI::queryMeetingByTimeInterval(void) {
	cout << "[query meetings] [start time(yyyy-mm-dd/hh:mm)] ";
	cout << "[end time(yyyy-mm-dd/hh:mm)]" << endl;
	cout << "[query meetings] ";
	string sTime, eTime;
	cin >> sTime >> eTime;
	Date sDate, eDate;
	sDate = Date::stringToDate(sTime);
	eDate = Date::stringToDate(eTime);
	if (sDate >eDate) {
		cout << "[error] wrong time interval!" << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
		return;
	}
	printMeetings(agendaService_.meetingQuery(currentUser_->getName(), sTime,eTime));
	cout << "Agenda@" << currentUser_->getName() << " : # ";
}
void AgendaUI::queryMeetingByTitle(void) {
	cout << "[query meeting] [title]" << endl;
	cout << "[query meeting] ";
	string title;
	cin >> title;
	Meeting *m;
	if(agendaService_.meetingQuery(title).empty())
		m=NULL;
	else
		m = &(agendaService_.meetingQuery(title).front());
	cout << endl;
	cout << setw(10) << "sponsor";
	cout << setw(15) << "participator";
	cout << setw(20) << "start time";
	cout << setw(20) << "end time" << endl;
	if (m == NULL) {
		cout << "Agenda@" << currentUser_->getName() << " : # ";
		return;
	}
	cout << setw(10) << m->getSponsor();
	cout << setw(15) << m->getParticipator();
	cout << setw(20) << Date::dateToString(m->getStartDate());
	cout << setw(20) << Date::dateToString(m->getEndDate());
	cout << endl << endl;
	cout << "Agenda@" << currentUser_->getName() << " : # ";
}
void AgendaUI::deleteMeetingByTitle(void) {
	cout << "[delete meeting] [title]" << endl;
	cout << "[delete meeting] ";
	string title;
	cin >> title;
	if (agendaService_.deleteMeeting(
		currentUser_->getName(), title)) {
			cout << "[delete meeting by title] succeed!" << endl << endl;
			cout << "Agenda@" << currentUser_->getName() << " : # ";
	} else {
		cout << "[error] delete meeting fail!" << endl << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
	}
}
void AgendaUI::deleteAllMeetings(void) {
	bool x;
	x = agendaService_.deleteAllMeetings(currentUser_->getName());
	if (x) {
		cout << "[delete all meetings] succeed!"<< endl << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
	} else {
		cout << "[error] delete all meetings fail!" << endl << endl;
		cout << "Agenda@" << currentUser_->getName() << " : # ";
	}
}
void AgendaUI::printMeetings(std::list<Meeting> meetings) {
	list<Meeting>::iterator it;
	cout << setw(10) << "title" << setw(10) <<"sponsor";
	cout << setw(15) << "participator";
	cout << setw(20) << "start time" << setw(20) << "end time" << endl;
	for (it = meetings.begin(); it != meetings.end(); it++) {
		cout << setw(10) << it->getTitle();
		cout << setw(10) << it->getSponsor();
		cout << setw(15) << it->getParticipator();
		cout << setw(20) << Date::dateToString(it->getStartDate());
		cout << setw(20) << Date::dateToString(it->getEndDate()) << endl;
	}
	cout << endl;
}
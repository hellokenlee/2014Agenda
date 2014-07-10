#include "Storage.h"
Storage *Storage::instance_ = nullptr;

Storage::Storage() {
  if (readFromFile("agenda.data") == false) {
    userList_.clear();
    meetingList_.clear();
  }
}

Storage* Storage::getInstance(void) {
  if (!instance_) {
  	instance_ = new Storage();
  }
  return instance_;
}

Storage::~Storage() {
  instance_=NULL;	
  writeToFile("agenda.data");
}

bool Storage::sync(void) {
  return writeToFile("agenda.data");
}

void Storage::createUser(const User& user_) {
  userList_.push_back(user_);
}

std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
  std::list<User> v;
  for (auto i : userList_) {
  	if (filter(i))
  	  v.push_back(i);
  }
  return v;
}

int Storage::updateUser(std::function<bool(const User&)> filter, std::function<void(User&)> switcher) {
  int result = 0;
  for (std::list<User>::iterator i=userList_.begin();i!=userList_.end();++i) {
  	if (filter(*i)) {
      switcher(*i);
  	  result++;
  	}
  }
  return result;
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {
  int result = 0;
  for (auto i = userList_.begin(); i != userList_.end();) {
  	if (filter(*i)) {
  	  userList_.erase(i++);
  	  result++;
  	}
	else
		++i;
  }
  return result;
}

void Storage::createMeeting(const Meeting& meeting_) {
  meetingList_.push_back(meeting_);
}

std::list<Meeting> Storage::queryMeeting(std::function<bool(const Meeting&)> filter) {
  std::list<Meeting> v;
  for (auto i : meetingList_) {
  	if (filter(i))
  	  v.push_back(i);
  }
  return v;
}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter, std::function<void(Meeting&)> switcher) {
  int result = 0;
  for (std::list<Meeting>::iterator i = meetingList_.begin(); i != meetingList_.end(); ++i) {
  	if (filter(*i)) {
      switcher(*i);
  	  result++;
  	}
  }
  return result;
}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
  int result = 0;
  for (auto i = meetingList_.begin(); i != meetingList_.end();) {
  	if (filter(*i)) {
  	  meetingList_.erase(i++);
  	  result++;
  	}
	else
	{
		++i;
	}
  }
  return result;
}
bool Storage::readFromFile(const char *filename) {
	std::ifstream fin(filename);
	if (!fin.good())
		return false;
	std::string raw_str;
	std::string num;
	std::stringstream st;
	int total;
	int pos=0;
	int n;
	//User
	fin>>raw_str;
	pos=raw_str.find(':',pos);
	pos++;
	pos=raw_str.find(':',pos);
	pos++;
	num=raw_str.erase(0,pos);
	num.erase(num.size()-1,1);
	st<<num;
	st>>n;
	for(int i=0;i<n;++i){
		pos=0;
		std::string name;
		std::string pwd;
		std::string email;
		std::string phone;
		fin>>raw_str;
		//name
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			name.append(1,raw_str.at(pos));
			pos++;
		}
		//password
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			pwd.append(1,raw_str.at(pos));
			pos++;
		}
		//email
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			email.append(1,raw_str.at(pos));
			pos++;
		}
		//phone
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			phone.append(1,raw_str.at(pos));
			pos++;
		}
		userList_.push_back(User(name,pwd,email,phone));
	}
	//Meetings
	fin>>raw_str;
	std::stringstream st2;
	pos=0;
	int n2;
	pos=raw_str.find(':',pos);
	pos++;
	pos=raw_str.find(':',pos);
	pos++;
	num=raw_str.erase(0,pos);
	num.erase(num.size()-1,1);
	st2<<num;
	st2>>n2;
	for(int i=0;i<n2;++i){
		pos=0;
		std::string sponser;
		std::string paticpater;
		std::string sTime;
		std::string eTime;
		std::string title;
		fin>>raw_str;
		//sponser
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			sponser.append(1,raw_str.at(pos));
			pos++;
		}
		//paticipater
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			paticpater.append(1,raw_str.at(pos));
			pos++;
		}
		//sTime
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			sTime.append(1,raw_str.at(pos));
			pos++;
		}
		//endTime
		pos=raw_str.find(':',pos);
		pos+=2;
		while(raw_str.at(pos)!='"'){
			eTime.append(1,raw_str.at(pos));
			pos++;
		}
		//title
		pos=raw_str.find(':',pos);
		pos+=2; 
		while(raw_str.at(pos)!='"'){
			title.append(1,raw_str.at(pos));
			pos++;
		}
		meetingList_.push_back(Meeting(sponser,paticpater,Date::stringToDate(sTime),Date::stringToDate(eTime),title));
	}
	return true;
}

bool Storage::writeToFile(const char *filename) {
	std::ofstream fout(filename);
	if (!fout.good())
		return false;
	fout << "{collection:\"User\",total:" << userList_.size() << "}" << std::endl;
	for (auto user : userList_) {
		fout << "{";
		fout << "name:\"" << user.getName() << "\",";
		fout << "password:\"" << user.getPassword() << "\",";
		fout << "email:\"" << user.getEmail() << "\",";
		fout << "phone:\"" << user.getPhone() << "\"";
		fout << "}" << std::endl;
	}
	fout << "{collection:\"Meeting\",total:" << meetingList_.size() << "}" << std::endl;
	for (auto meeting : meetingList_) {
		fout << "{";
		fout << "sponsor:\"" << meeting.getSponsor() << "\",";
		fout << "participator:\"" << meeting.getParticipator() << "\",";
		fout << "sdate:\"" << Date::dateToString(meeting.getStartDate()) << "\",";
		fout << "edate:\"" << Date::dateToString(meeting.getEndDate()) << "\",";
		fout << "title:\"" << meeting.getTitle() << "\"";
		fout << "}" << std::endl;
	}
	return true;
}



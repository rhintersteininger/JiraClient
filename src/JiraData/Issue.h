////  To parse this JSON data, first install
////
////      Boost     http://www.boost.org
////      json.hpp  https://github.com/nlohmann/json
////
////  Then include this file, and then do
////
////     Issue data = nlohmann::json::parse(jsonString);
//
//#pragma once
//#include <nlohmann/json.hpp>
//#include <boost/optional.hpp>
//#include <stdexcept>
//#include <regex>
//
//namespace Jira {
//    namespace Data {
//        using nlohmann::json;
//
//        inline json get_untyped(const json& j, const char* property) {
//            if (j.find(property) != j.end()) {
//                return j.at(property).get<json>();
//            }
//            return json();
//        }
//
//        inline json get_untyped(const json& j, std::string property) {
//            return get_untyped(j, property.data());
//        }
//
//        class Progress {
//        public:
//            Progress() = default;
//            virtual ~Progress() = default;
//
//        private:
//            int64_t progress;
//            int64_t total;
//            int64_t percent;
//
//        public:
//            const int64_t& get_progress() const { return progress; }
//            int64_t& get_mutable_progress() { return progress; }
//            void set_progress(const int64_t& value) { this->progress = value; }
//
//            const int64_t& get_total() const { return total; }
//            int64_t& get_mutable_total() { return total; }
//            void set_total(const int64_t& value) { this->total = value; }
//
//            const int64_t& get_percent() const { return percent; }
//            int64_t& get_mutable_percent() { return percent; }
//            void set_percent(const int64_t& value) { this->percent = value; }
//        };
//
//        class AvatarUrls {
//        public:
//            AvatarUrls() = default;
//            virtual ~AvatarUrls() = default;
//
//        private:
//            std::string the_48_x48;
//            std::string the_24_x24;
//            std::string the_16_x16;
//            std::string the_32_x32;
//
//        public:
//            const std::string& get_the_48__x48() const { return the_48_x48; }
//            std::string& get_mutable_the_48__x48() { return the_48_x48; }
//            void set_the_48__x48(const std::string& value) { this->the_48_x48 = value; }
//
//            const std::string& get_the_24__x24() const { return the_24_x24; }
//            std::string& get_mutable_the_24__x24() { return the_24_x24; }
//            void set_the_24__x24(const std::string& value) { this->the_24_x24 = value; }
//
//            const std::string& get_the_16__x16() const { return the_16_x16; }
//            std::string& get_mutable_the_16__x16() { return the_16_x16; }
//            void set_the_16__x16(const std::string& value) { this->the_16_x16 = value; }
//
//            const std::string& get_the_32__x32() const { return the_32_x32; }
//            std::string& get_mutable_the_32__x32() { return the_32_x32; }
//            void set_the_32__x32(const std::string& value) { this->the_32_x32 = value; }
//        };
//
//        class Assignee {
//        public:
//            Assignee() = default;
//            virtual ~Assignee() = default;
//
//        private:
//            std::string self;
//            std::string account_id;
//            std::string email_address;
//            AvatarUrls avatar_urls;
//            std::string display_name;
//            bool active;
//            std::string time_zone;
//            std::string account_type;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const std::string& get_account_id() const { return account_id; }
//            std::string& get_mutable_account_id() { return account_id; }
//            void set_account_id(const std::string& value) { this->account_id = value; }
//
//            const std::string& get_email_address() const { return email_address; }
//            std::string& get_mutable_email_address() { return email_address; }
//            void set_email_address(const std::string& value) { this->email_address = value; }
//
//            const AvatarUrls& get_avatar_urls() const { return avatar_urls; }
//            AvatarUrls& get_mutable_avatar_urls() { return avatar_urls; }
//            void set_avatar_urls(const AvatarUrls& value) { this->avatar_urls = value; }
//
//            const std::string& get_display_name() const { return display_name; }
//            std::string& get_mutable_display_name() { return display_name; }
//            void set_display_name(const std::string& value) { this->display_name = value; }
//
//            const bool& get_active() const { return active; }
//            bool& get_mutable_active() { return active; }
//            void set_active(const bool& value) { this->active = value; }
//
//            const std::string& get_time_zone() const { return time_zone; }
//            std::string& get_mutable_time_zone() { return time_zone; }
//            void set_time_zone(const std::string& value) { this->time_zone = value; }
//
//            const std::string& get_account_type() const { return account_type; }
//            std::string& get_mutable_account_type() { return account_type; }
//            void set_account_type(const std::string& value) { this->account_type = value; }
//        };
//
//        class NonEditableReason {
//        public:
//            NonEditableReason() = default;
//            virtual ~NonEditableReason() = default;
//
//        private:
//            std::string reason;
//            std::string message;
//
//        public:
//            const std::string& get_reason() const { return reason; }
//            std::string& get_mutable_reason() { return reason; }
//            void set_reason(const std::string& value) { this->reason = value; }
//
//            const std::string& get_message() const { return message; }
//            std::string& get_mutable_message() { return message; }
//            void set_message(const std::string& value) { this->message = value; }
//        };
//
//        class Customfield10018 {
//        public:
//            Customfield10018() = default;
//            virtual ~Customfield10018() = default;
//
//        private:
//            bool has_epic_link_field_dependency;
//            bool show_field;
//            NonEditableReason non_editable_reason;
//
//        public:
//            const bool& get_has_epic_link_field_dependency() const { return has_epic_link_field_dependency; }
//            bool& get_mutable_has_epic_link_field_dependency() { return has_epic_link_field_dependency; }
//            void set_has_epic_link_field_dependency(const bool& value) { this->has_epic_link_field_dependency = value; }
//
//            const bool& get_show_field() const { return show_field; }
//            bool& get_mutable_show_field() { return show_field; }
//            void set_show_field(const bool& value) { this->show_field = value; }
//
//            const NonEditableReason& get_non_editable_reason() const { return non_editable_reason; }
//            NonEditableReason& get_mutable_non_editable_reason() { return non_editable_reason; }
//            void set_non_editable_reason(const NonEditableReason& value) { this->non_editable_reason = value; }
//        };
//
//        class Issuetype {
//        public:
//            Issuetype() = default;
//            virtual ~Issuetype() = default;
//
//        private:
//            std::string self;
//            std::string id;
//            std::string description;
//            std::string icon_url;
//            std::string name;
//            bool subtask;
//            int64_t avatar_id;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const std::string& get_id() const { return id; }
//            std::string& get_mutable_id() { return id; }
//            void set_id(const std::string& value) { this->id = value; }
//
//            const std::string& get_description() const { return description; }
//            std::string& get_mutable_description() { return description; }
//            void set_description(const std::string& value) { this->description = value; }
//
//            const std::string& get_icon_url() const { return icon_url; }
//            std::string& get_mutable_icon_url() { return icon_url; }
//            void set_icon_url(const std::string& value) { this->icon_url = value; }
//
//            const std::string& get_name() const { return name; }
//            std::string& get_mutable_name() { return name; }
//            void set_name(const std::string& value) { this->name = value; }
//
//            const bool& get_subtask() const { return subtask; }
//            bool& get_mutable_subtask() { return subtask; }
//            void set_subtask(const bool& value) { this->subtask = value; }
//
//            const int64_t& get_avatar_id() const { return avatar_id; }
//            int64_t& get_mutable_avatar_id() { return avatar_id; }
//            void set_avatar_id(const int64_t& value) { this->avatar_id = value; }
//        };
//
//        class Priority {
//        public:
//            Priority() = default;
//            virtual ~Priority() = default;
//
//        private:
//            std::string self;
//            std::string icon_url;
//            std::string name;
//            std::string id;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const std::string& get_icon_url() const { return icon_url; }
//            std::string& get_mutable_icon_url() { return icon_url; }
//            void set_icon_url(const std::string& value) { this->icon_url = value; }
//
//            const std::string& get_name() const { return name; }
//            std::string& get_mutable_name() { return name; }
//            void set_name(const std::string& value) { this->name = value; }
//
//            const std::string& get_id() const { return id; }
//            std::string& get_mutable_id() { return id; }
//            void set_id(const std::string& value) { this->id = value; }
//        };
//
//        class Project {
//        public:
//            Project() = default;
//            virtual ~Project() = default;
//
//        private:
//            std::string self;
//            std::string id;
//            std::string key;
//            std::string name;
//            std::string project_type_key;
//            bool simplified;
//            AvatarUrls avatar_urls;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const std::string& get_id() const { return id; }
//            std::string& get_mutable_id() { return id; }
//            void set_id(const std::string& value) { this->id = value; }
//
//            const std::string& get_key() const { return key; }
//            std::string& get_mutable_key() { return key; }
//            void set_key(const std::string& value) { this->key = value; }
//
//            const std::string& get_name() const { return name; }
//            std::string& get_mutable_name() { return name; }
//            void set_name(const std::string& value) { this->name = value; }
//
//            const std::string& get_project_type_key() const { return project_type_key; }
//            std::string& get_mutable_project_type_key() { return project_type_key; }
//            void set_project_type_key(const std::string& value) { this->project_type_key = value; }
//
//            const bool& get_simplified() const { return simplified; }
//            bool& get_mutable_simplified() { return simplified; }
//            void set_simplified(const bool& value) { this->simplified = value; }
//
//            const AvatarUrls& get_avatar_urls() const { return avatar_urls; }
//            AvatarUrls& get_mutable_avatar_urls() { return avatar_urls; }
//            void set_avatar_urls(const AvatarUrls& value) { this->avatar_urls = value; }
//        };
//
//        class StatusCategory {
//        public:
//            StatusCategory() = default;
//            virtual ~StatusCategory() = default;
//
//        private:
//            std::string self;
//            int64_t id;
//            std::string key;
//            std::string color_name;
//            std::string name;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const int64_t& get_id() const { return id; }
//            int64_t& get_mutable_id() { return id; }
//            void set_id(const int64_t& value) { this->id = value; }
//
//            const std::string& get_key() const { return key; }
//            std::string& get_mutable_key() { return key; }
//            void set_key(const std::string& value) { this->key = value; }
//
//            const std::string& get_color_name() const { return color_name; }
//            std::string& get_mutable_color_name() { return color_name; }
//            void set_color_name(const std::string& value) { this->color_name = value; }
//
//            const std::string& get_name() const { return name; }
//            std::string& get_mutable_name() { return name; }
//            void set_name(const std::string& value) { this->name = value; }
//        };
//
//        class Status {
//        public:
//            Status() = default;
//            virtual ~Status() = default;
//
//        private:
//            std::string self;
//            std::string description;
//            std::string icon_url;
//            std::string name;
//            std::string id;
//            StatusCategory status_category;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const std::string& get_description() const { return description; }
//            std::string& get_mutable_description() { return description; }
//            void set_description(const std::string& value) { this->description = value; }
//
//            const std::string& get_icon_url() const { return icon_url; }
//            std::string& get_mutable_icon_url() { return icon_url; }
//            void set_icon_url(const std::string& value) { this->icon_url = value; }
//
//            const std::string& get_name() const { return name; }
//            std::string& get_mutable_name() { return name; }
//            void set_name(const std::string& value) { this->name = value; }
//
//            const std::string& get_id() const { return id; }
//            std::string& get_mutable_id() { return id; }
//            void set_id(const std::string& value) { this->id = value; }
//
//            const StatusCategory& get_status_category() const { return status_category; }
//            StatusCategory& get_mutable_status_category() { return status_category; }
//            void set_status_category(const StatusCategory& value) { this->status_category = value; }
//        };
//
//        class Votes {
//        public:
//            Votes() = default;
//            virtual ~Votes() = default;
//
//        private:
//            std::string self;
//            int64_t votes;
//            bool has_voted;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const int64_t& get_votes() const { return votes; }
//            int64_t& get_mutable_votes() { return votes; }
//            void set_votes(const int64_t& value) { this->votes = value; }
//
//            const bool& get_has_voted() const { return has_voted; }
//            bool& get_mutable_has_voted() { return has_voted; }
//            void set_has_voted(const bool& value) { this->has_voted = value; }
//        };
//
//        class Watches {
//        public:
//            Watches() = default;
//            virtual ~Watches() = default;
//
//        private:
//            std::string self;
//            int64_t watch_count;
//            bool is_watching;
//
//        public:
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const int64_t& get_watch_count() const { return watch_count; }
//            int64_t& get_mutable_watch_count() { return watch_count; }
//            void set_watch_count(const int64_t& value) { this->watch_count = value; }
//
//            const bool& get_is_watching() const { return is_watching; }
//            bool& get_mutable_is_watching() { return is_watching; }
//            void set_is_watching(const bool& value) { this->is_watching = value; }
//        };
//
//        class Fields {
//        public:
//            Fields() = default;
//            virtual ~Fields() = default;
//
//        private:
//            std::string statuscategorychangedate;
//            Issuetype issuetype;
//            int64_t timespent;
//            Project project;
//            std::vector<nlohmann::json> fix_versions;
//            int64_t aggregatetimespent;
//            nlohmann::json resolution;
//            nlohmann::json customfield_10028;
//            nlohmann::json resolutiondate;
//            int64_t workratio;
//            std::string last_viewed;
//            Watches watches;
//            std::string created;
//            nlohmann::json customfield_10020;
//            nlohmann::json customfield_10021;
//            nlohmann::json customfield_10022;
//            nlohmann::json customfield_10023;
//            Priority priority;
//            nlohmann::json customfield_10024;
//            nlohmann::json customfield_10025;
//            std::vector<nlohmann::json> labels;
//            nlohmann::json customfield_10016;
//            nlohmann::json customfield_10017;
//            Customfield10018 customfield_10018;
//            std::string customfield_10019;
//            int64_t timeestimate;
//            nlohmann::json aggregatetimeoriginalestimate;
//            std::vector<nlohmann::json> versions;
//            std::vector<nlohmann::json> issuelinks;
//            Assignee assignee;
//            std::string updated;
//            Status status;
//            std::vector<nlohmann::json> components;
//            nlohmann::json timeoriginalestimate;
//            std::string description;
//            nlohmann::json customfield_10010;
//            nlohmann::json customfield_10014;
//            nlohmann::json customfield_10015;
//            nlohmann::json customfield_10005;
//            nlohmann::json customfield_10006;
//            nlohmann::json customfield_10007;
//            nlohmann::json security;
//            nlohmann::json customfield_10008;
//            nlohmann::json customfield_10009;
//            int64_t aggregatetimeestimate;
//            std::string summary;
//            Assignee creator;
//            std::vector<nlohmann::json> subtasks;
//            Assignee reporter;
//            Progress aggregateprogress;
//            std::string customfield_10000;
//            nlohmann::json customfield_10001;
//            nlohmann::json customfield_10002;
//            nlohmann::json customfield_10003;
//            nlohmann::json customfield_10004;
//            nlohmann::json environment;
//            nlohmann::json duedate;
//            Progress progress;
//            Votes votes;
//
//        public:
//            const std::string& get_statuscategorychangedate() const { return statuscategorychangedate; }
//            std::string& get_mutable_statuscategorychangedate() { return statuscategorychangedate; }
//            void set_statuscategorychangedate(const std::string& value) { this->statuscategorychangedate = value; }
//
//            const Issuetype& get_issuetype() const { return issuetype; }
//            Issuetype& get_mutable_issuetype() { return issuetype; }
//            void set_issuetype(const Issuetype& value) { this->issuetype = value; }
//
//            const int64_t& get_timespent() const { return timespent; }
//            int64_t& get_mutable_timespent() { return timespent; }
//            void set_timespent(const int64_t& value) { this->timespent = value; }
//
//            const Project& get_project() const { return project; }
//            Project& get_mutable_project() { return project; }
//            void set_project(const Project& value) { this->project = value; }
//
//            const std::vector<nlohmann::json>& get_fix_versions() const { return fix_versions; }
//            std::vector<nlohmann::json>& get_mutable_fix_versions() { return fix_versions; }
//            void set_fix_versions(const std::vector<nlohmann::json>& value) { this->fix_versions = value; }
//
//            const int64_t& get_aggregatetimespent() const { return aggregatetimespent; }
//            int64_t& get_mutable_aggregatetimespent() { return aggregatetimespent; }
//            void set_aggregatetimespent(const int64_t& value) { this->aggregatetimespent = value; }
//
//            const nlohmann::json& get_resolution() const { return resolution; }
//            nlohmann::json& get_mutable_resolution() { return resolution; }
//            void set_resolution(const nlohmann::json& value) { this->resolution = value; }
//
//            const nlohmann::json& get_customfield_10028() const { return customfield_10028; }
//            nlohmann::json& get_mutable_customfield_10028() { return customfield_10028; }
//            void set_customfield_10028(const nlohmann::json& value) { this->customfield_10028 = value; }
//
//            const nlohmann::json& get_resolutiondate() const { return resolutiondate; }
//            nlohmann::json& get_mutable_resolutiondate() { return resolutiondate; }
//            void set_resolutiondate(const nlohmann::json& value) { this->resolutiondate = value; }
//
//            const int64_t& get_workratio() const { return workratio; }
//            int64_t& get_mutable_workratio() { return workratio; }
//            void set_workratio(const int64_t& value) { this->workratio = value; }
//
//            const std::string& get_last_viewed() const { return last_viewed; }
//            std::string& get_mutable_last_viewed() { return last_viewed; }
//            void set_last_viewed(const std::string& value) { this->last_viewed = value; }
//
//            const Watches& get_watches() const { return watches; }
//            Watches& get_mutable_watches() { return watches; }
//            void set_watches(const Watches& value) { this->watches = value; }
//
//            const std::string& get_created() const { return created; }
//            std::string& get_mutable_created() { return created; }
//            void set_created(const std::string& value) { this->created = value; }
//
//            const nlohmann::json& get_customfield_10020() const { return customfield_10020; }
//            nlohmann::json& get_mutable_customfield_10020() { return customfield_10020; }
//            void set_customfield_10020(const nlohmann::json& value) { this->customfield_10020 = value; }
//
//            const nlohmann::json& get_customfield_10021() const { return customfield_10021; }
//            nlohmann::json& get_mutable_customfield_10021() { return customfield_10021; }
//            void set_customfield_10021(const nlohmann::json& value) { this->customfield_10021 = value; }
//
//            const nlohmann::json& get_customfield_10022() const { return customfield_10022; }
//            nlohmann::json& get_mutable_customfield_10022() { return customfield_10022; }
//            void set_customfield_10022(const nlohmann::json& value) { this->customfield_10022 = value; }
//
//            const nlohmann::json& get_customfield_10023() const { return customfield_10023; }
//            nlohmann::json& get_mutable_customfield_10023() { return customfield_10023; }
//            void set_customfield_10023(const nlohmann::json& value) { this->customfield_10023 = value; }
//
//            const Priority& get_priority() const { return priority; }
//            Priority& get_mutable_priority() { return priority; }
//            void set_priority(const Priority& value) { this->priority = value; }
//
//            const nlohmann::json& get_customfield_10024() const { return customfield_10024; }
//            nlohmann::json& get_mutable_customfield_10024() { return customfield_10024; }
//            void set_customfield_10024(const nlohmann::json& value) { this->customfield_10024 = value; }
//
//            const nlohmann::json& get_customfield_10025() const { return customfield_10025; }
//            nlohmann::json& get_mutable_customfield_10025() { return customfield_10025; }
//            void set_customfield_10025(const nlohmann::json& value) { this->customfield_10025 = value; }
//
//            const std::vector<nlohmann::json>& get_labels() const { return labels; }
//            std::vector<nlohmann::json>& get_mutable_labels() { return labels; }
//            void set_labels(const std::vector<nlohmann::json>& value) { this->labels = value; }
//
//            const nlohmann::json& get_customfield_10016() const { return customfield_10016; }
//            nlohmann::json& get_mutable_customfield_10016() { return customfield_10016; }
//            void set_customfield_10016(const nlohmann::json& value) { this->customfield_10016 = value; }
//
//            const nlohmann::json& get_customfield_10017() const { return customfield_10017; }
//            nlohmann::json& get_mutable_customfield_10017() { return customfield_10017; }
//            void set_customfield_10017(const nlohmann::json& value) { this->customfield_10017 = value; }
//
//            const Customfield10018& get_customfield_10018() const { return customfield_10018; }
//            Customfield10018& get_mutable_customfield_10018() { return customfield_10018; }
//            void set_customfield_10018(const Customfield10018& value) { this->customfield_10018 = value; }
//
//            const std::string& get_customfield_10019() const { return customfield_10019; }
//            std::string& get_mutable_customfield_10019() { return customfield_10019; }
//            void set_customfield_10019(const std::string& value) { this->customfield_10019 = value; }
//
//            const int64_t& get_timeestimate() const { return timeestimate; }
//            int64_t& get_mutable_timeestimate() { return timeestimate; }
//            void set_timeestimate(const int64_t& value) { this->timeestimate = value; }
//
//            const nlohmann::json& get_aggregatetimeoriginalestimate() const { return aggregatetimeoriginalestimate; }
//            nlohmann::json& get_mutable_aggregatetimeoriginalestimate() { return aggregatetimeoriginalestimate; }
//            void set_aggregatetimeoriginalestimate(const nlohmann::json& value) { this->aggregatetimeoriginalestimate = value; }
//
//            const std::vector<nlohmann::json>& get_versions() const { return versions; }
//            std::vector<nlohmann::json>& get_mutable_versions() { return versions; }
//            void set_versions(const std::vector<nlohmann::json>& value) { this->versions = value; }
//
//            const std::vector<nlohmann::json>& get_issuelinks() const { return issuelinks; }
//            std::vector<nlohmann::json>& get_mutable_issuelinks() { return issuelinks; }
//            void set_issuelinks(const std::vector<nlohmann::json>& value) { this->issuelinks = value; }
//
//            const Assignee& get_assignee() const { return assignee; }
//            Assignee& get_mutable_assignee() { return assignee; }
//            void set_assignee(const Assignee& value) { this->assignee = value; }
//
//            const std::string& get_updated() const { return updated; }
//            std::string& get_mutable_updated() { return updated; }
//            void set_updated(const std::string& value) { this->updated = value; }
//
//            const Status& get_status() const { return status; }
//            Status& get_mutable_status() { return status; }
//            void set_status(const Status& value) { this->status = value; }
//
//            const std::vector<nlohmann::json>& get_components() const { return components; }
//            std::vector<nlohmann::json>& get_mutable_components() { return components; }
//            void set_components(const std::vector<nlohmann::json>& value) { this->components = value; }
//
//            const nlohmann::json& get_timeoriginalestimate() const { return timeoriginalestimate; }
//            nlohmann::json& get_mutable_timeoriginalestimate() { return timeoriginalestimate; }
//            void set_timeoriginalestimate(const nlohmann::json& value) { this->timeoriginalestimate = value; }
//
//            const std::string& get_description() const { return description; }
//            std::string& get_mutable_description() { return description; }
//            void set_description(const std::string& value) { this->description = value; }
//
//            const nlohmann::json& get_customfield_10010() const { return customfield_10010; }
//            nlohmann::json& get_mutable_customfield_10010() { return customfield_10010; }
//            void set_customfield_10010(const nlohmann::json& value) { this->customfield_10010 = value; }
//
//            const nlohmann::json& get_customfield_10014() const { return customfield_10014; }
//            nlohmann::json& get_mutable_customfield_10014() { return customfield_10014; }
//            void set_customfield_10014(const nlohmann::json& value) { this->customfield_10014 = value; }
//
//            const nlohmann::json& get_customfield_10015() const { return customfield_10015; }
//            nlohmann::json& get_mutable_customfield_10015() { return customfield_10015; }
//            void set_customfield_10015(const nlohmann::json& value) { this->customfield_10015 = value; }
//
//            const nlohmann::json& get_customfield_10005() const { return customfield_10005; }
//            nlohmann::json& get_mutable_customfield_10005() { return customfield_10005; }
//            void set_customfield_10005(const nlohmann::json& value) { this->customfield_10005 = value; }
//
//            const nlohmann::json& get_customfield_10006() const { return customfield_10006; }
//            nlohmann::json& get_mutable_customfield_10006() { return customfield_10006; }
//            void set_customfield_10006(const nlohmann::json& value) { this->customfield_10006 = value; }
//
//            const nlohmann::json& get_customfield_10007() const { return customfield_10007; }
//            nlohmann::json& get_mutable_customfield_10007() { return customfield_10007; }
//            void set_customfield_10007(const nlohmann::json& value) { this->customfield_10007 = value; }
//
//            const nlohmann::json& get_security() const { return security; }
//            nlohmann::json& get_mutable_security() { return security; }
//            void set_security(const nlohmann::json& value) { this->security = value; }
//
//            const nlohmann::json& get_customfield_10008() const { return customfield_10008; }
//            nlohmann::json& get_mutable_customfield_10008() { return customfield_10008; }
//            void set_customfield_10008(const nlohmann::json& value) { this->customfield_10008 = value; }
//
//            const nlohmann::json& get_customfield_10009() const { return customfield_10009; }
//            nlohmann::json& get_mutable_customfield_10009() { return customfield_10009; }
//            void set_customfield_10009(const nlohmann::json& value) { this->customfield_10009 = value; }
//
//            const int64_t& get_aggregatetimeestimate() const { return aggregatetimeestimate; }
//            int64_t& get_mutable_aggregatetimeestimate() { return aggregatetimeestimate; }
//            void set_aggregatetimeestimate(const int64_t& value) { this->aggregatetimeestimate = value; }
//
//            const std::string& get_summary() const { return summary; }
//            std::string& get_mutable_summary() { return summary; }
//            void set_summary(const std::string& value) { this->summary = value; }
//
//            const Assignee& get_creator() const { return creator; }
//            Assignee& get_mutable_creator() { return creator; }
//            void set_creator(const Assignee& value) { this->creator = value; }
//
//            const std::vector<nlohmann::json>& get_subtasks() const { return subtasks; }
//            std::vector<nlohmann::json>& get_mutable_subtasks() { return subtasks; }
//            void set_subtasks(const std::vector<nlohmann::json>& value) { this->subtasks = value; }
//
//            const Assignee& get_reporter() const { return reporter; }
//            Assignee& get_mutable_reporter() { return reporter; }
//            void set_reporter(const Assignee& value) { this->reporter = value; }
//
//            const Progress& get_aggregateprogress() const { return aggregateprogress; }
//            Progress& get_mutable_aggregateprogress() { return aggregateprogress; }
//            void set_aggregateprogress(const Progress& value) { this->aggregateprogress = value; }
//
//            const std::string& get_customfield_10000() const { return customfield_10000; }
//            std::string& get_mutable_customfield_10000() { return customfield_10000; }
//            void set_customfield_10000(const std::string& value) { this->customfield_10000 = value; }
//
//            const nlohmann::json& get_customfield_10001() const { return customfield_10001; }
//            nlohmann::json& get_mutable_customfield_10001() { return customfield_10001; }
//            void set_customfield_10001(const nlohmann::json& value) { this->customfield_10001 = value; }
//
//            const nlohmann::json& get_customfield_10002() const { return customfield_10002; }
//            nlohmann::json& get_mutable_customfield_10002() { return customfield_10002; }
//            void set_customfield_10002(const nlohmann::json& value) { this->customfield_10002 = value; }
//
//            const nlohmann::json& get_customfield_10003() const { return customfield_10003; }
//            nlohmann::json& get_mutable_customfield_10003() { return customfield_10003; }
//            void set_customfield_10003(const nlohmann::json& value) { this->customfield_10003 = value; }
//
//            const nlohmann::json& get_customfield_10004() const { return customfield_10004; }
//            nlohmann::json& get_mutable_customfield_10004() { return customfield_10004; }
//            void set_customfield_10004(const nlohmann::json& value) { this->customfield_10004 = value; }
//
//            const nlohmann::json& get_environment() const { return environment; }
//            nlohmann::json& get_mutable_environment() { return environment; }
//            void set_environment(const nlohmann::json& value) { this->environment = value; }
//
//            const nlohmann::json& get_duedate() const { return duedate; }
//            nlohmann::json& get_mutable_duedate() { return duedate; }
//            void set_duedate(const nlohmann::json& value) { this->duedate = value; }
//
//            const Progress& get_progress() const { return progress; }
//            Progress& get_mutable_progress() { return progress; }
//            void set_progress(const Progress& value) { this->progress = value; }
//
//            const Votes& get_votes() const { return votes; }
//            Votes& get_mutable_votes() { return votes; }
//            void set_votes(const Votes& value) { this->votes = value; }
//        };
//
//        class Issue {
//        public:
//            Issue() = default;
//            virtual ~Issue() = default;
//
//        private:
//            std::string expand;
//            std::string id;
//            std::string self;
//            std::string key;
//            Fields fields;
//
//        public:
//            const std::string& get_expand() const { return expand; }
//            std::string& get_mutable_expand() { return expand; }
//            void set_expand(const std::string& value) { this->expand = value; }
//
//            const std::string& get_id() const { return id; }
//            std::string& get_mutable_id() { return id; }
//            void set_id(const std::string& value) { this->id = value; }
//
//            const std::string& get_self() const { return self; }
//            std::string& get_mutable_self() { return self; }
//            void set_self(const std::string& value) { this->self = value; }
//
//            const std::string& get_key() const { return key; }
//            std::string& get_mutable_key() { return key; }
//            void set_key(const std::string& value) { this->key = value; }
//
//            const Fields& get_fields() const { return fields; }
//            Fields& get_mutable_fields() { return fields; }
//            void set_fields(const Fields& value) { this->fields = value; }
//        };
//    }
//}
//
//namespace nlohmann {
//    void from_json(const json& j, Jira::Data::Progress& x);
//    void to_json(json& j, const Jira::Data::Progress& x);
//
//    void from_json(const json& j, Jira::Data::AvatarUrls& x);
//    void to_json(json& j, const Jira::Data::AvatarUrls& x);
//
//    void from_json(const json& j, Jira::Data::Assignee& x);
//    void to_json(json& j, const Jira::Data::Assignee& x);
//
//    void from_json(const json& j, Jira::Data::NonEditableReason& x);
//    void to_json(json& j, const Jira::Data::NonEditableReason& x);
//
//    void from_json(const json& j, Jira::Data::Customfield10018& x);
//    void to_json(json& j, const Jira::Data::Customfield10018& x);
//
//    void from_json(const json& j, Jira::Data::Issuetype& x);
//    void to_json(json& j, const Jira::Data::Issuetype& x);
//
//    void from_json(const json& j, Jira::Data::Priority& x);
//    void to_json(json& j, const Jira::Data::Priority& x);
//
//    void from_json(const json& j, Jira::Data::Project& x);
//    void to_json(json& j, const Jira::Data::Project& x);
//
//    void from_json(const json& j, Jira::Data::StatusCategory& x);
//    void to_json(json& j, const Jira::Data::StatusCategory& x);
//
//    void from_json(const json& j, Jira::Data::Status& x);
//    void to_json(json& j, const Jira::Data::Status& x);
//
//    void from_json(const json& j, Jira::Data::Votes& x);
//    void to_json(json& j, const Jira::Data::Votes& x);
//
//    void from_json(const json& j, Jira::Data::Watches& x);
//    void to_json(json& j, const Jira::Data::Watches& x);
//
//    void from_json(const json& j, Jira::Data::Fields& x);
//    void to_json(json& j, const Jira::Data::Fields& x);
//
//    void from_json(const json& j, Jira::Data::Issue& x);
//    void to_json(json& j, const Jira::Data::Issue& x);
//
//    inline void from_json(const json& j, Jira::Data::Progress& x) {
//        x.set_progress(j.at("progress").get<int64_t>());
//        x.set_total(j.at("total").get<int64_t>());
//        x.set_percent(j.at("percent").get<int64_t>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Progress& x) {
//        j = json::object();
//        j["progress"] = x.get_progress();
//        j["total"] = x.get_total();
//        j["percent"] = x.get_percent();
//    }
//
//    inline void from_json(const json& j, Jira::Data::AvatarUrls& x) {
//        x.set_the_48__x48(j.at("48x48").get<std::string>());
//        x.set_the_24__x24(j.at("24x24").get<std::string>());
//        x.set_the_16__x16(j.at("16x16").get<std::string>());
//        x.set_the_32__x32(j.at("32x32").get<std::string>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::AvatarUrls& x) {
//        j = json::object();
//        j["48x48"] = x.get_the_48__x48();
//        j["24x24"] = x.get_the_24__x24();
//        j["16x16"] = x.get_the_16__x16();
//        j["32x32"] = x.get_the_32__x32();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Assignee& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_account_id(j.at("accountId").get<std::string>());
//        x.set_email_address(j.at("emailAddress").get<std::string>());
//        x.set_avatar_urls(j.at("avatarUrls").get<Jira::Data::AvatarUrls>());
//        x.set_display_name(j.at("displayName").get<std::string>());
//        x.set_active(j.at("active").get<bool>());
//        x.set_time_zone(j.at("timeZone").get<std::string>());
//        x.set_account_type(j.at("accountType").get<std::string>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Assignee& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["accountId"] = x.get_account_id();
//        j["emailAddress"] = x.get_email_address();
//        j["avatarUrls"] = x.get_avatar_urls();
//        j["displayName"] = x.get_display_name();
//        j["active"] = x.get_active();
//        j["timeZone"] = x.get_time_zone();
//        j["accountType"] = x.get_account_type();
//    }
//
//    inline void from_json(const json& j, Jira::Data::NonEditableReason& x) {
//        x.set_reason(j.at("reason").get<std::string>());
//        x.set_message(j.at("message").get<std::string>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::NonEditableReason& x) {
//        j = json::object();
//        j["reason"] = x.get_reason();
//        j["message"] = x.get_message();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Customfield10018& x) {
//        x.set_has_epic_link_field_dependency(j.at("hasEpicLinkFieldDependency").get<bool>());
//        x.set_show_field(j.at("showField").get<bool>());
//        x.set_non_editable_reason(j.at("nonEditableReason").get<Jira::Data::NonEditableReason>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Customfield10018& x) {
//        j = json::object();
//        j["hasEpicLinkFieldDependency"] = x.get_has_epic_link_field_dependency();
//        j["showField"] = x.get_show_field();
//        j["nonEditableReason"] = x.get_non_editable_reason();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Issuetype& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_id(j.at("id").get<std::string>());
//        x.set_description(j.at("description").get<std::string>());
//        x.set_icon_url(j.at("iconUrl").get<std::string>());
//        x.set_name(j.at("name").get<std::string>());
//        x.set_subtask(j.at("subtask").get<bool>());
//        x.set_avatar_id(j.at("avatarId").get<int64_t>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Issuetype& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["id"] = x.get_id();
//        j["description"] = x.get_description();
//        j["iconUrl"] = x.get_icon_url();
//        j["name"] = x.get_name();
//        j["subtask"] = x.get_subtask();
//        j["avatarId"] = x.get_avatar_id();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Priority& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_icon_url(j.at("iconUrl").get<std::string>());
//        x.set_name(j.at("name").get<std::string>());
//        x.set_id(j.at("id").get<std::string>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Priority& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["iconUrl"] = x.get_icon_url();
//        j["name"] = x.get_name();
//        j["id"] = x.get_id();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Project& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_id(j.at("id").get<std::string>());
//        x.set_key(j.at("key").get<std::string>());
//        x.set_name(j.at("name").get<std::string>());
//        x.set_project_type_key(j.at("projectTypeKey").get<std::string>());
//        x.set_simplified(j.at("simplified").get<bool>());
//        x.set_avatar_urls(j.at("avatarUrls").get<Jira::Data::AvatarUrls>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Project& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["id"] = x.get_id();
//        j["key"] = x.get_key();
//        j["name"] = x.get_name();
//        j["projectTypeKey"] = x.get_project_type_key();
//        j["simplified"] = x.get_simplified();
//        j["avatarUrls"] = x.get_avatar_urls();
//    }
//
//    inline void from_json(const json& j, Jira::Data::StatusCategory& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_id(j.at("id").get<int64_t>());
//        x.set_key(j.at("key").get<std::string>());
//        x.set_color_name(j.at("colorName").get<std::string>());
//        x.set_name(j.at("name").get<std::string>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::StatusCategory& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["id"] = x.get_id();
//        j["key"] = x.get_key();
//        j["colorName"] = x.get_color_name();
//        j["name"] = x.get_name();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Status& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_description(j.at("description").get<std::string>());
//        x.set_icon_url(j.at("iconUrl").get<std::string>());
//        x.set_name(j.at("name").get<std::string>());
//        x.set_id(j.at("id").get<std::string>());
//        x.set_status_category(j.at("statusCategory").get<Jira::Data::StatusCategory>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Status& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["description"] = x.get_description();
//        j["iconUrl"] = x.get_icon_url();
//        j["name"] = x.get_name();
//        j["id"] = x.get_id();
//        j["statusCategory"] = x.get_status_category();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Votes& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_votes(j.at("votes").get<int64_t>());
//        x.set_has_voted(j.at("hasVoted").get<bool>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Votes& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["votes"] = x.get_votes();
//        j["hasVoted"] = x.get_has_voted();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Watches& x) {
//        x.set_self(j.at("self").get<std::string>());
//        x.set_watch_count(j.at("watchCount").get<int64_t>());
//        x.set_is_watching(j.at("isWatching").get<bool>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Watches& x) {
//        j = json::object();
//        j["self"] = x.get_self();
//        j["watchCount"] = x.get_watch_count();
//        j["isWatching"] = x.get_is_watching();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Fields& x) {
//        x.set_statuscategorychangedate(j.at("statuscategorychangedate").get<std::string>());
//        x.set_issuetype(j.at("issuetype").get<Jira::Data::Issuetype>());
//        x.set_timespent(j.at("timespent").get<int64_t>());
//        x.set_project(j.at("project").get<Jira::Data::Project>());
//        x.set_fix_versions(j.at("fixVersions").get<std::vector<json>>());
//        x.set_aggregatetimespent(j.at("aggregatetimespent").get<int64_t>());
//        x.set_resolution(Jira::Data::get_untyped(j, "resolution"));
//        x.set_customfield_10028(Jira::Data::get_untyped(j, "customfield_10028"));
//        x.set_resolutiondate(Jira::Data::get_untyped(j, "resolutiondate"));
//        x.set_workratio(j.at("workratio").get<int64_t>());
//        x.set_last_viewed(j.at("lastViewed").get<std::string>());
//        x.set_watches(j.at("watches").get<Jira::Data::Watches>());
//        x.set_created(j.at("created").get<std::string>());
//        x.set_customfield_10020(Jira::Data::get_untyped(j, "customfield_10020"));
//        x.set_customfield_10021(Jira::Data::get_untyped(j, "customfield_10021"));
//        x.set_customfield_10022(Jira::Data::get_untyped(j, "customfield_10022"));
//        x.set_customfield_10023(Jira::Data::get_untyped(j, "customfield_10023"));
//        x.set_priority(j.at("priority").get<Jira::Data::Priority>());
//        x.set_customfield_10024(Jira::Data::get_untyped(j, "customfield_10024"));
//        x.set_customfield_10025(Jira::Data::get_untyped(j, "customfield_10025"));
//        x.set_labels(j.at("labels").get<std::vector<json>>());
//        x.set_customfield_10016(Jira::Data::get_untyped(j, "customfield_10016"));
//        x.set_customfield_10017(Jira::Data::get_untyped(j, "customfield_10017"));
//        x.set_customfield_10018(j.at("customfield_10018").get<Jira::Data::Customfield10018>());
//        x.set_customfield_10019(j.at("customfield_10019").get<std::string>());
//        x.set_timeestimate(j.at("timeestimate").get<int64_t>());
//        x.set_aggregatetimeoriginalestimate(Jira::Data::get_untyped(j, "aggregatetimeoriginalestimate"));
//        x.set_versions(j.at("versions").get<std::vector<json>>());
//        x.set_issuelinks(j.at("issuelinks").get<std::vector<json>>());
//        x.set_assignee(j.at("assignee").get<Jira::Data::Assignee>());
//        x.set_updated(j.at("updated").get<std::string>());
//        x.set_status(j.at("status").get<Jira::Data::Status>());
//        x.set_components(j.at("components").get<std::vector<json>>());
//        x.set_timeoriginalestimate(Jira::Data::get_untyped(j, "timeoriginalestimate"));
//        x.set_description(j.at("description").get<std::string>());
//        x.set_customfield_10010(Jira::Data::get_untyped(j, "customfield_10010"));
//        x.set_customfield_10014(Jira::Data::get_untyped(j, "customfield_10014"));
//        x.set_customfield_10015(Jira::Data::get_untyped(j, "customfield_10015"));
//        x.set_customfield_10005(Jira::Data::get_untyped(j, "customfield_10005"));
//        x.set_customfield_10006(Jira::Data::get_untyped(j, "customfield_10006"));
//        x.set_customfield_10007(Jira::Data::get_untyped(j, "customfield_10007"));
//        x.set_security(Jira::Data::get_untyped(j, "security"));
//        x.set_customfield_10008(Jira::Data::get_untyped(j, "customfield_10008"));
//        x.set_customfield_10009(Jira::Data::get_untyped(j, "customfield_10009"));
//        x.set_aggregatetimeestimate(j.at("aggregatetimeestimate").get<int64_t>());
//        x.set_summary(j.at("summary").get<std::string>());
//        x.set_creator(j.at("creator").get<Jira::Data::Assignee>());
//        x.set_subtasks(j.at("subtasks").get<std::vector<json>>());
//        x.set_reporter(j.at("reporter").get<Jira::Data::Assignee>());
//        x.set_aggregateprogress(j.at("aggregateprogress").get<Jira::Data::Progress>());
//        x.set_customfield_10000(j.at("customfield_10000").get<std::string>());
//        x.set_customfield_10001(Jira::Data::get_untyped(j, "customfield_10001"));
//        x.set_customfield_10002(Jira::Data::get_untyped(j, "customfield_10002"));
//        x.set_customfield_10003(Jira::Data::get_untyped(j, "customfield_10003"));
//        x.set_customfield_10004(Jira::Data::get_untyped(j, "customfield_10004"));
//        x.set_environment(Jira::Data::get_untyped(j, "environment"));
//        x.set_duedate(Jira::Data::get_untyped(j, "duedate"));
//        x.set_progress(j.at("progress").get<Jira::Data::Progress>());
//        x.set_votes(j.at("votes").get<Jira::Data::Votes>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Fields& x) {
//        j = json::object();
//        j["statuscategorychangedate"] = x.get_statuscategorychangedate();
//        j["issuetype"] = x.get_issuetype();
//        j["timespent"] = x.get_timespent();
//        j["project"] = x.get_project();
//        j["fixVersions"] = x.get_fix_versions();
//        j["aggregatetimespent"] = x.get_aggregatetimespent();
//        j["resolution"] = x.get_resolution();
//        j["customfield_10028"] = x.get_customfield_10028();
//        j["resolutiondate"] = x.get_resolutiondate();
//        j["workratio"] = x.get_workratio();
//        j["lastViewed"] = x.get_last_viewed();
//        j["watches"] = x.get_watches();
//        j["created"] = x.get_created();
//        j["customfield_10020"] = x.get_customfield_10020();
//        j["customfield_10021"] = x.get_customfield_10021();
//        j["customfield_10022"] = x.get_customfield_10022();
//        j["customfield_10023"] = x.get_customfield_10023();
//        j["priority"] = x.get_priority();
//        j["customfield_10024"] = x.get_customfield_10024();
//        j["customfield_10025"] = x.get_customfield_10025();
//        j["labels"] = x.get_labels();
//        j["customfield_10016"] = x.get_customfield_10016();
//        j["customfield_10017"] = x.get_customfield_10017();
//        j["customfield_10018"] = x.get_customfield_10018();
//        j["customfield_10019"] = x.get_customfield_10019();
//        j["timeestimate"] = x.get_timeestimate();
//        j["aggregatetimeoriginalestimate"] = x.get_aggregatetimeoriginalestimate();
//        j["versions"] = x.get_versions();
//        j["issuelinks"] = x.get_issuelinks();
//        j["assignee"] = x.get_assignee();
//        j["updated"] = x.get_updated();
//        j["status"] = x.get_status();
//        j["components"] = x.get_components();
//        j["timeoriginalestimate"] = x.get_timeoriginalestimate();
//        j["description"] = x.get_description();
//        j["customfield_10010"] = x.get_customfield_10010();
//        j["customfield_10014"] = x.get_customfield_10014();
//        j["customfield_10015"] = x.get_customfield_10015();
//        j["customfield_10005"] = x.get_customfield_10005();
//        j["customfield_10006"] = x.get_customfield_10006();
//        j["customfield_10007"] = x.get_customfield_10007();
//        j["security"] = x.get_security();
//        j["customfield_10008"] = x.get_customfield_10008();
//        j["customfield_10009"] = x.get_customfield_10009();
//        j["aggregatetimeestimate"] = x.get_aggregatetimeestimate();
//        j["summary"] = x.get_summary();
//        j["creator"] = x.get_creator();
//        j["subtasks"] = x.get_subtasks();
//        j["reporter"] = x.get_reporter();
//        j["aggregateprogress"] = x.get_aggregateprogress();
//        j["customfield_10000"] = x.get_customfield_10000();
//        j["customfield_10001"] = x.get_customfield_10001();
//        j["customfield_10002"] = x.get_customfield_10002();
//        j["customfield_10003"] = x.get_customfield_10003();
//        j["customfield_10004"] = x.get_customfield_10004();
//        j["environment"] = x.get_environment();
//        j["duedate"] = x.get_duedate();
//        j["progress"] = x.get_progress();
//        j["votes"] = x.get_votes();
//    }
//
//    inline void from_json(const json& j, Jira::Data::Issue& x) {
//        x.set_expand(j.at("expand").get<std::string>());
//        x.set_id(j.at("id").get<std::string>());
//        x.set_self(j.at("self").get<std::string>());
//        x.set_key(j.at("key").get<std::string>());
//        x.set_fields(j.at("fields").get<Jira::Data::Fields>());
//    }
//
//    inline void to_json(json& j, const Jira::Data::Issue& x) {
//        j = json::object();
//        j["expand"] = x.get_expand();
//        j["id"] = x.get_id();
//        j["self"] = x.get_self();
//        j["key"] = x.get_key();
//        j["fields"] = x.get_fields();
//    }
//}

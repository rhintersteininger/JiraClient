#pragma once

//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     GetUser data = nlohmann::json::parse(jsonString);

#pragma once

#include <nlohmann/json.hpp>

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json& j, const std::shared_ptr<T>& opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json& j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace Jira {
    namespace Data {
        using nlohmann::json;

      
        class Group {
        public:
            Group() = default;
            virtual ~Group() = default;

        private:
            std::shared_ptr<std::string> name;
            std::shared_ptr<std::string> self;

        public:
            std::shared_ptr<std::string> get_name() const { return name; }
            void set_name(std::shared_ptr<std::string> value) { this->name = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }
        };

        class SimpleListWrapper {
        public:
            SimpleListWrapper() = default;
            virtual ~SimpleListWrapper() = default;

        private:
            std::shared_ptr<std::vector<Group>> items;
            std::shared_ptr<int64_t> max_results;
            int64_t size;

        public:
            std::shared_ptr<std::vector<Group>> get_items() const { return items; }
            void set_items(std::shared_ptr<std::vector<Group>> value) { this->items = value; }

            std::shared_ptr<int64_t> get_max_results() const { return max_results; }
            void set_max_results(std::shared_ptr<int64_t> value) { this->max_results = value; }

            const int64_t& get_size() const { return size; }
            int64_t& get_mutable_size() { return size; }
            void set_size(const int64_t& value) { this->size = value; }
        };


        class GetUser {
        public:
            GetUser() = default;
            virtual ~GetUser() = default;

        private:
            bool active;
            std::shared_ptr<SimpleListWrapper> application_roles;
            std::shared_ptr<AvatarUrls> avatar_urls;
            std::shared_ptr<std::string> display_name;
            std::shared_ptr<std::string> email_address;
            std::shared_ptr<std::string> expand;
            std::shared_ptr<SimpleListWrapper> groups;
            std::shared_ptr<std::string> key;
            std::shared_ptr<std::string> locale;
            std::shared_ptr<std::string> name;
            std::shared_ptr<std::string> self;
            std::shared_ptr<std::string> time_zone;

        public:
            const bool& get_active() const { return active; }
            bool& get_mutable_active() { return active; }
            void set_active(const bool& value) { this->active = value; }

            std::shared_ptr<SimpleListWrapper> get_application_roles() const { return application_roles; }
            void set_application_roles(std::shared_ptr<SimpleListWrapper> value) { this->application_roles = value; }

            std::shared_ptr<AvatarUrls> get_avatar_urls() const { return avatar_urls; }
            void set_avatar_urls(std::shared_ptr<AvatarUrls> value) { this->avatar_urls = value; }

            std::shared_ptr<std::string> get_display_name() const { return display_name; }
            void set_display_name(std::shared_ptr<std::string> value) { this->display_name = value; }

            std::shared_ptr<std::string> get_email_address() const { return email_address; }
            void set_email_address(std::shared_ptr<std::string> value) { this->email_address = value; }

            std::shared_ptr<std::string> get_expand() const { return expand; }
            void set_expand(std::shared_ptr<std::string> value) { this->expand = value; }

            std::shared_ptr<SimpleListWrapper> get_groups() const { return groups; }
            void set_groups(std::shared_ptr<SimpleListWrapper> value) { this->groups = value; }

            std::shared_ptr<std::string> get_key() const { return key; }
            void set_key(std::shared_ptr<std::string> value) { this->key = value; }

            std::shared_ptr<std::string> get_locale() const { return locale; }
            void set_locale(std::shared_ptr<std::string> value) { this->locale = value; }

            std::shared_ptr<std::string> get_name() const { return name; }
            void set_name(std::shared_ptr<std::string> value) { this->name = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }

            std::shared_ptr<std::string> get_time_zone() const { return time_zone; }
            void set_time_zone(std::shared_ptr<std::string> value) { this->time_zone = value; }
        };
    }
}

namespace nlohmann {
    void from_json(const json& j, Jira::Data::Group& x);
    void to_json(json& j, const Jira::Data::Group& x);

    void from_json(const json& j, Jira::Data::SimpleListWrapper& x);
    void to_json(json& j, const Jira::Data::SimpleListWrapper& x);


    void from_json(const json& j, Jira::Data::GetUser& x);
    void to_json(json& j, const Jira::Data::GetUser& x);

    inline void from_json(const json& j, Jira::Data::Group& x) {
        x.set_name(Jira::Data::get_optional<std::string>(j, "name"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
    }

    inline void to_json(json& j, const Jira::Data::Group& x) {
        j = json::object();
        j["name"] = x.get_name();
        j["self"] = x.get_self();
    }

    inline void from_json(const json& j, Jira::Data::SimpleListWrapper& x) {
        x.set_items(Jira::Data::get_optional<std::vector<Jira::Data::Group>>(j, "items"));
        x.set_max_results(Jira::Data::get_optional<int64_t>(j, "max-results"));
        x.set_size(j.at("size").get<int64_t>());
    }

    inline void to_json(json& j, const Jira::Data::SimpleListWrapper& x) {
        j = json::object();
        j["items"] = x.get_items();
        j["max-results"] = x.get_max_results();
        j["size"] = x.get_size();
    }

    

    inline void from_json(const json& j, Jira::Data::GetUser& x) {
        x.set_active(j.at("active").get<bool>());
        x.set_application_roles(Jira::Data::get_optional<Jira::Data::SimpleListWrapper>(j, "applicationRoles"));
        x.set_avatar_urls(Jira::Data::get_optional<Jira::Data::AvatarUrls>(j, "avatarUrls"));
        x.set_display_name(Jira::Data::get_optional<std::string>(j, "displayName"));
        x.set_email_address(Jira::Data::get_optional<std::string>(j, "emailAddress"));
        x.set_expand(Jira::Data::get_optional<std::string>(j, "expand"));
        x.set_groups(Jira::Data::get_optional<Jira::Data::SimpleListWrapper>(j, "groups"));
        x.set_key(Jira::Data::get_optional<std::string>(j, "key"));
        x.set_locale(Jira::Data::get_optional<std::string>(j, "locale"));
        x.set_name(Jira::Data::get_optional<std::string>(j, "name"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
        x.set_time_zone(Jira::Data::get_optional<std::string>(j, "timeZone"));
    }

    inline void to_json(json& j, const Jira::Data::GetUser& x) {
        j = json::object();
        j["active"] = x.get_active();
        j["applicationRoles"] = x.get_application_roles();
        j["avatarUrls"] = x.get_avatar_urls();
        j["displayName"] = x.get_display_name();
        j["emailAddress"] = x.get_email_address();
        j["expand"] = x.get_expand();
        j["groups"] = x.get_groups();
        j["key"] = x.get_key();
        j["locale"] = x.get_locale();
        j["name"] = x.get_name();
        j["self"] = x.get_self();
        j["timeZone"] = x.get_time_zone();
    }
}


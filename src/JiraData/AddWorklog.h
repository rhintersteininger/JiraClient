#pragma once

//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     AddWorklog data = nlohmann::json::parse(jsonString);

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
    
        enum class Type : int { GROUP, ROLE };

        class Visibility {
        public:
            Visibility() = default;
            virtual ~Visibility() = default;

        private:
            std::shared_ptr<Type> type;
            std::shared_ptr<std::string> value;

        public:
            std::shared_ptr<Type> get_type() const { return type; }
            void set_type(std::shared_ptr<Type> value) { this->type = value; }

            std::shared_ptr<std::string> get_value() const { return value; }
            void set_value(std::shared_ptr<std::string> value) { this->value = value; }
        };

        class AddWorklog {
        public:
            AddWorklog() = default;
            virtual ~AddWorklog() = default;

        private:
            std::shared_ptr<User> author;
            std::shared_ptr<std::string> comment;
            std::shared_ptr<std::string> created;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> issue_id;
            std::shared_ptr<std::string> started;
            std::shared_ptr<std::string> time_spent;
            std::shared_ptr<int64_t> time_spent_seconds;
            std::shared_ptr<User> update_author;
            std::shared_ptr<std::string> updated;
            std::shared_ptr<Visibility> visibility;

        public:
            std::shared_ptr<User> get_author() const { return author; }
            void set_author(std::shared_ptr<User> value) { this->author = value; }

            std::shared_ptr<std::string> get_comment() const { return comment; }
            void set_comment(std::shared_ptr<std::string> value) { this->comment = value; }

            std::shared_ptr<std::string> get_created() const { return created; }
            void set_created(std::shared_ptr<std::string> value) { this->created = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_issue_id() const { return issue_id; }
            void set_issue_id(std::shared_ptr<std::string> value) { this->issue_id = value; }

            std::shared_ptr<std::string> get_started() const { return started; }
            void set_started(std::shared_ptr<std::string> value) { this->started = value; }

            std::shared_ptr<std::string> get_time_spent() const { return time_spent; }
            void set_time_spent(std::shared_ptr<std::string> value) { this->time_spent = value; }

            std::shared_ptr<int64_t> get_time_spent_seconds() const { return time_spent_seconds; }
            void set_time_spent_seconds(std::shared_ptr<int64_t> value) { this->time_spent_seconds = value; }

            std::shared_ptr<User> get_update_author() const { return update_author; }
            void set_update_author(std::shared_ptr<User> value) { this->update_author = value; }

            std::shared_ptr<std::string> get_updated() const { return updated; }
            void set_updated(std::shared_ptr<std::string> value) { this->updated = value; }

            std::shared_ptr<Visibility> get_visibility() const { return visibility; }
            void set_visibility(std::shared_ptr<Visibility> value) { this->visibility = value; }
        };
    }
}

namespace nlohmann {
    void from_json(const json& j, Jira::Data::AvatarUrls& x);
    void to_json(json& j, const Jira::Data::AvatarUrls& x);

    void from_json(const json& j, Jira::Data::User& x);
    void to_json(json& j, const Jira::Data::User& x);

    void from_json(const json& j, Jira::Data::Visibility& x);
    void to_json(json& j, const Jira::Data::Visibility& x);

    void from_json(const json& j, Jira::Data::AddWorklog& x);
    void to_json(json& j, const Jira::Data::AddWorklog& x);

    void from_json(const json& j, Jira::Data::Type& x);
    void to_json(json& j, const Jira::Data::Type& x);


    inline void from_json(const json& j, Jira::Data::Visibility& x) {
        x.set_type(Jira::Data::get_optional<Jira::Data::Type>(j, "type"));
        x.set_value(Jira::Data::get_optional<std::string>(j, "value"));
    }

    inline void to_json(json& j, const Jira::Data::Visibility& x) {
        j = json::object();
        j["type"] = x.get_type();
        j["value"] = x.get_value();
    }

    inline void from_json(const json& j, Jira::Data::AddWorklog& x) {
        x.set_author(Jira::Data::get_optional<Jira::Data::User>(j, "author"));
        x.set_comment(Jira::Data::get_optional<std::string>(j, "comment"));
        x.set_created(Jira::Data::get_optional<std::string>(j, "created"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_issue_id(Jira::Data::get_optional<std::string>(j, "issueId"));
        x.set_started(Jira::Data::get_optional<std::string>(j, "started"));
        x.set_time_spent(Jira::Data::get_optional<std::string>(j, "timeSpent"));
        x.set_time_spent_seconds(Jira::Data::get_optional<int64_t>(j, "timeSpentSeconds"));
        x.set_update_author(Jira::Data::get_optional<Jira::Data::User>(j, "updateAuthor"));
        x.set_updated(Jira::Data::get_optional<std::string>(j, "updated"));
        x.set_visibility(Jira::Data::get_optional<Jira::Data::Visibility>(j, "visibility"));
    }

    inline void to_json(json& j, const Jira::Data::AddWorklog& x) {
        j = json::object();
        if (x.get_author() != nullptr)
            j["author"] = x.get_author();      
        if (x.get_comment() != nullptr)
            j["comment"] = x.get_comment();
        if (x.get_created() != nullptr)
            j["created"] = x.get_created();
        if (x.get_id() != nullptr)
            j["id"] = x.get_id();
        if (x.get_issue_id() != nullptr)
            j["issueId"] = x.get_issue_id();
        if (x.get_started() != nullptr)
            j["started"] = x.get_started();
        if (x.get_time_spent() != nullptr)
            j["timeSpent"] = x.get_time_spent();
        if (x.get_time_spent_seconds() != nullptr)
            j["timeSpentSeconds"] = x.get_time_spent_seconds();
        if (x.get_update_author() != nullptr)
            j["updateAuthor"] = x.get_update_author();
        if (x.get_updated() != nullptr)
            j["updated"] = x.get_updated();
        if (x.get_visibility() != nullptr)
        j["visibility"] = x.get_visibility();
    }

    inline void from_json(const json& j, Jira::Data::Type& x) {
        if (j == "group") x = Jira::Data::Type::GROUP;
        else if (j == "role") x = Jira::Data::Type::ROLE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json& j, const Jira::Data::Type& x) {
        switch (x) {
        case Jira::Data::Type::GROUP: j = "group"; break;
        case Jira::Data::Type::ROLE: j = "role"; break;
        default: throw "This should not happen";
        }
    }
}


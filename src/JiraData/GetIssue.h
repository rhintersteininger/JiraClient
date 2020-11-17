#pragma once

//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     GetIssue data = nlohmann::json::parse(jsonString);

#include "SearchResult.h"

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

        class GetIssueFields {
        public:
            GetIssueFields() = default;
            virtual ~GetIssueFields() = default;

        private:
            std::shared_ptr<std::string> summary;

        public:
            std::shared_ptr<std::string> get_summary() const { return summary; }
            void set_summary(std::shared_ptr<std::string> value) { this->summary = value; }
        };

        class Names {
        public:
            Names() = default;
            virtual ~Names() = default;

        private:

        public:
        };

        class Schema {
        public:
            Schema() = default;
            virtual ~Schema() = default;

        private:

        public:
        };

        class GetIssue {
        public:
            GetIssue() = default;
            virtual ~GetIssue() = default;

        private:
            std::shared_ptr<Changelog> changelog;
            std::shared_ptr<EditMeta> editmeta;
            std::shared_ptr<std::string> expand;
            std::shared_ptr<GetIssueFields> fields;
            std::shared_ptr<std::map<std::string, nlohmann::json>> fields_to_include;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> key;
            std::shared_ptr<Names> names;
            std::shared_ptr<Opsbar> operations;
            std::shared_ptr<Properties> properties;
            std::shared_ptr<RenderedFields> rendered_fields;
            std::shared_ptr<Schema> schema;
            std::shared_ptr<std::string> self;
            std::shared_ptr<std::vector<Transition>> transitions;
            std::shared_ptr<VersionedRepresentations> versioned_representations;

        public:
            std::shared_ptr<Changelog> get_changelog() const { return changelog; }
            void set_changelog(std::shared_ptr<Changelog> value) { this->changelog = value; }

            std::shared_ptr<EditMeta> get_editmeta() const { return editmeta; }
            void set_editmeta(std::shared_ptr<EditMeta> value) { this->editmeta = value; }

            std::shared_ptr<std::string> get_expand() const { return expand; }
            void set_expand(std::shared_ptr<std::string> value) { this->expand = value; }

            std::shared_ptr<GetIssueFields> get_fields() const { return fields; }
            void set_fields(std::shared_ptr<GetIssueFields> value) { this->fields = value; }

            std::shared_ptr<std::map<std::string, nlohmann::json>> get_fields_to_include() const { return fields_to_include; }
            void set_fields_to_include(std::shared_ptr<std::map<std::string, nlohmann::json>> value) { this->fields_to_include = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_key() const { return key; }
            void set_key(std::shared_ptr<std::string> value) { this->key = value; }

            std::shared_ptr<Names> get_names() const { return names; }
            void set_names(std::shared_ptr<Names> value) { this->names = value; }

            std::shared_ptr<Opsbar> get_operations() const { return operations; }
            void set_operations(std::shared_ptr<Opsbar> value) { this->operations = value; }

            std::shared_ptr<Properties> get_properties() const { return properties; }
            void set_properties(std::shared_ptr<Properties> value) { this->properties = value; }

            std::shared_ptr<RenderedFields> get_rendered_fields() const { return rendered_fields; }
            void set_rendered_fields(std::shared_ptr<RenderedFields> value) { this->rendered_fields = value; }

            std::shared_ptr<Schema> get_schema() const { return schema; }
            void set_schema(std::shared_ptr<Schema> value) { this->schema = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }

            std::shared_ptr<std::vector<Transition>> get_transitions() const { return transitions; }
            void set_transitions(std::shared_ptr<std::vector<Transition>> value) { this->transitions = value; }

            std::shared_ptr<VersionedRepresentations> get_versioned_representations() const { return versioned_representations; }
            void set_versioned_representations(std::shared_ptr<VersionedRepresentations> value) { this->versioned_representations = value; }
        };
    }
}

namespace nlohmann {
    void from_json(const json& j, Jira::Data::AvatarUrls& x);
    void to_json(json& j, const Jira::Data::AvatarUrls& x);

    void from_json(const json& j, Jira::Data::User& x);
    void to_json(json& j, const Jira::Data::User& x);

    void from_json(const json& j, Jira::Data::HistoryMetadataParticipant& x);
    void to_json(json& j, const Jira::Data::HistoryMetadataParticipant& x);

    void from_json(const json& j, Jira::Data::ExtraData& x);
    void to_json(json& j, const Jira::Data::ExtraData& x);

    void from_json(const json& j, Jira::Data::HistoryMetadata& x);
    void to_json(json& j, const Jira::Data::HistoryMetadata& x);

    void from_json(const json& j, Jira::Data::ChangeItem& x);
    void to_json(json& j, const Jira::Data::ChangeItem& x);

    void from_json(const json& j, Jira::Data::ChangeHistory& x);
    void to_json(json& j, const Jira::Data::ChangeHistory& x);

    void from_json(const json& j, Jira::Data::Changelog& x);
    void to_json(json& j, const Jira::Data::Changelog& x);

    void from_json(const json& j, Jira::Data::EditmetaFields& x);
    void to_json(json& j, const Jira::Data::EditmetaFields& x);

    void from_json(const json& j, Jira::Data::EditMeta& x);
    void to_json(json& j, const Jira::Data::EditMeta& x);

    void from_json(const json& j, Jira::Data::GetIssueFields& x);
    void to_json(json& j, const Jira::Data::GetIssueFields& x);

    void from_json(const json& j, Jira::Data::Names& x);
    void to_json(json& j, const Jira::Data::Names& x);

    void from_json(const json& j, Jira::Data::SimpleLink& x);
    void to_json(json& j, const Jira::Data::SimpleLink& x);

    void from_json(const json& j, Jira::Data::LinkGroup& x);
    void to_json(json& j, const Jira::Data::LinkGroup& x);

    void from_json(const json& j, Jira::Data::Opsbar& x);
    void to_json(json& j, const Jira::Data::Opsbar& x);

    void from_json(const json& j, Jira::Data::PropertiesProperties& x);
    void to_json(json& j, const Jira::Data::PropertiesProperties& x);

    void from_json(const json& j, Jira::Data::Properties& x);
    void to_json(json& j, const Jira::Data::Properties& x);

    void from_json(const json& j, Jira::Data::RenderedFields& x);
    void to_json(json& j, const Jira::Data::RenderedFields& x);

    void from_json(const json& j, Jira::Data::Schema& x);
    void to_json(json& j, const Jira::Data::Schema& x);

    void from_json(const json& j, Jira::Data::TransitionFields& x);
    void to_json(json& j, const Jira::Data::TransitionFields& x);

    void from_json(const json& j, Jira::Data::StatusCategory& x);
    void to_json(json& j, const Jira::Data::StatusCategory& x);

    void from_json(const json& j, Jira::Data::Status& x);
    void to_json(json& j, const Jira::Data::Status& x);

    void from_json(const json& j, Jira::Data::Transition& x);
    void to_json(json& j, const Jira::Data::Transition& x);

    void from_json(const json& j, Jira::Data::VersionedRepresentations& x);
    void to_json(json& j, const Jira::Data::VersionedRepresentations& x);

    void from_json(const json& j, Jira::Data::GetIssue& x);
    void to_json(json& j, const Jira::Data::GetIssue& x);

   
    inline void from_json(const json& j, Jira::Data::GetIssueFields& x) {
        x.set_summary(Jira::Data::get_optional<std::string>(j, "summary"));
    }

    inline void to_json(json& j, const Jira::Data::GetIssueFields& x) {
        j = json::object();
        j["summary"] = x.get_summary();
    }

    inline void from_json(const json& j, Jira::Data::Names& x) {
    }

    inline void to_json(json& j, const Jira::Data::Names& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::Schema& x) {
    }

    inline void to_json(json& j, const Jira::Data::Schema& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::GetIssue& x) {
        x.set_changelog(Jira::Data::get_optional<Jira::Data::Changelog>(j, "changelog"));
        x.set_editmeta(Jira::Data::get_optional<Jira::Data::EditMeta>(j, "editmeta"));
        x.set_expand(Jira::Data::get_optional<std::string>(j, "expand"));
        x.set_fields(Jira::Data::get_optional<Jira::Data::GetIssueFields>(j, "fields"));
        x.set_fields_to_include(Jira::Data::get_optional<std::map<std::string, json>>(j, "fieldsToInclude"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_key(Jira::Data::get_optional<std::string>(j, "key"));
        x.set_names(Jira::Data::get_optional<Jira::Data::Names>(j, "names"));
        x.set_operations(Jira::Data::get_optional<Jira::Data::Opsbar>(j, "operations"));
        x.set_properties(Jira::Data::get_optional<Jira::Data::Properties>(j, "properties"));
        x.set_rendered_fields(Jira::Data::get_optional<Jira::Data::RenderedFields>(j, "renderedFields"));
        x.set_schema(Jira::Data::get_optional<Jira::Data::Schema>(j, "schema"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
        x.set_transitions(Jira::Data::get_optional<std::vector<Jira::Data::Transition>>(j, "transitions"));
        x.set_versioned_representations(Jira::Data::get_optional<Jira::Data::VersionedRepresentations>(j, "versionedRepresentations"));
    }

    inline void to_json(json& j, const Jira::Data::GetIssue& x) {
        j = json::object();
        j["changelog"] = x.get_changelog();
        j["editmeta"] = x.get_editmeta();
        j["expand"] = x.get_expand();
        j["fields"] = x.get_fields();
        j["fieldsToInclude"] = x.get_fields_to_include();
        j["id"] = x.get_id();
        j["key"] = x.get_key();
        j["names"] = x.get_names();
        j["operations"] = x.get_operations();
        j["properties"] = x.get_properties();
        j["renderedFields"] = x.get_rendered_fields();
        j["schema"] = x.get_schema();
        j["self"] = x.get_self();
        j["transitions"] = x.get_transitions();
        j["versionedRepresentations"] = x.get_versioned_representations();
    }
}

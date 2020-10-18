#pragma once
//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     SearchResults data = nlohmann::json::parse(jsonString);

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

        inline json get_untyped(const json& j, const char* property) {
            if (j.find(property) != j.end()) {
                return j.at(property).get<json>();
            }
            return json();
        }

        inline json get_untyped(const json& j, std::string property) {
            return get_untyped(j, property.data());
        }

        template <typename T>
        inline std::shared_ptr<T> get_optional(const json& j, const char* property) {
            if (j.find(property) != j.end()) {
                return j.at(property).get<std::shared_ptr<T>>();
            }
            return std::shared_ptr<T>();
        }

        template <typename T>
        inline std::shared_ptr<T> get_optional(const json& j, std::string property) {
            return get_optional<T>(j, property.data());
        }

        class AvatarUrls {
        public:
            AvatarUrls() = default;
            virtual ~AvatarUrls() = default;

        private:

        public:
        };

        class User {
        public:
            User() = default;
            virtual ~User() = default;

        private:
            bool active;
            std::shared_ptr<AvatarUrls> avatar_urls;
            std::shared_ptr<std::string> display_name;
            std::shared_ptr<std::string> email_address;
            std::shared_ptr<std::string> key;
            std::shared_ptr<std::string> name;
            std::shared_ptr<std::string> self;
            std::shared_ptr<std::string> time_zone;

        public:
            const bool& get_active() const { return active; }
            bool& get_mutable_active() { return active; }
            void set_active(const bool& value) { this->active = value; }

            std::shared_ptr<AvatarUrls> get_avatar_urls() const { return avatar_urls; }
            void set_avatar_urls(std::shared_ptr<AvatarUrls> value) { this->avatar_urls = value; }

            std::shared_ptr<std::string> get_display_name() const { return display_name; }
            void set_display_name(std::shared_ptr<std::string> value) { this->display_name = value; }

            std::shared_ptr<std::string> get_email_address() const { return email_address; }
            void set_email_address(std::shared_ptr<std::string> value) { this->email_address = value; }

            std::shared_ptr<std::string> get_key() const { return key; }
            void set_key(std::shared_ptr<std::string> value) { this->key = value; }

            std::shared_ptr<std::string> get_name() const { return name; }
            void set_name(std::shared_ptr<std::string> value) { this->name = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }

            std::shared_ptr<std::string> get_time_zone() const { return time_zone; }
            void set_time_zone(std::shared_ptr<std::string> value) { this->time_zone = value; }
        };

        class HistoryMetadataParticipant {
        public:
            HistoryMetadataParticipant() = default;
            virtual ~HistoryMetadataParticipant() = default;

        private:
            std::shared_ptr<std::string> avatar_url;
            std::shared_ptr<std::string> display_name;
            std::shared_ptr<std::string> display_name_key;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> type;
            std::shared_ptr<std::string> url;

        public:
            std::shared_ptr<std::string> get_avatar_url() const { return avatar_url; }
            void set_avatar_url(std::shared_ptr<std::string> value) { this->avatar_url = value; }

            std::shared_ptr<std::string> get_display_name() const { return display_name; }
            void set_display_name(std::shared_ptr<std::string> value) { this->display_name = value; }

            std::shared_ptr<std::string> get_display_name_key() const { return display_name_key; }
            void set_display_name_key(std::shared_ptr<std::string> value) { this->display_name_key = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_type() const { return type; }
            void set_type(std::shared_ptr<std::string> value) { this->type = value; }

            std::shared_ptr<std::string> get_url() const { return url; }
            void set_url(std::shared_ptr<std::string> value) { this->url = value; }
        };

        class ExtraData {
        public:
            ExtraData() = default;
            virtual ~ExtraData() = default;

        private:

        public:
        };

        class HistoryMetadata {
        public:
            HistoryMetadata() = default;
            virtual ~HistoryMetadata() = default;

        private:
            std::shared_ptr<std::string> activity_description;
            std::shared_ptr<std::string> activity_description_key;
            std::shared_ptr<HistoryMetadataParticipant> actor;
            std::shared_ptr<HistoryMetadataParticipant> cause;
            std::shared_ptr<std::string> description;
            std::shared_ptr<std::string> description_key;
            std::shared_ptr<std::string> email_description;
            std::shared_ptr<std::string> email_description_key;
            std::shared_ptr<ExtraData> extra_data;
            std::shared_ptr<HistoryMetadataParticipant> generator;
            std::shared_ptr<std::string> type;

        public:
            std::shared_ptr<std::string> get_activity_description() const { return activity_description; }
            void set_activity_description(std::shared_ptr<std::string> value) { this->activity_description = value; }

            std::shared_ptr<std::string> get_activity_description_key() const { return activity_description_key; }
            void set_activity_description_key(std::shared_ptr<std::string> value) { this->activity_description_key = value; }

            std::shared_ptr<HistoryMetadataParticipant> get_actor() const { return actor; }
            void set_actor(std::shared_ptr<HistoryMetadataParticipant> value) { this->actor = value; }

            std::shared_ptr<HistoryMetadataParticipant> get_cause() const { return cause; }
            void set_cause(std::shared_ptr<HistoryMetadataParticipant> value) { this->cause = value; }

            std::shared_ptr<std::string> get_description() const { return description; }
            void set_description(std::shared_ptr<std::string> value) { this->description = value; }

            std::shared_ptr<std::string> get_description_key() const { return description_key; }
            void set_description_key(std::shared_ptr<std::string> value) { this->description_key = value; }

            std::shared_ptr<std::string> get_email_description() const { return email_description; }
            void set_email_description(std::shared_ptr<std::string> value) { this->email_description = value; }

            std::shared_ptr<std::string> get_email_description_key() const { return email_description_key; }
            void set_email_description_key(std::shared_ptr<std::string> value) { this->email_description_key = value; }

            std::shared_ptr<ExtraData> get_extra_data() const { return extra_data; }
            void set_extra_data(std::shared_ptr<ExtraData> value) { this->extra_data = value; }

            std::shared_ptr<HistoryMetadataParticipant> get_generator() const { return generator; }
            void set_generator(std::shared_ptr<HistoryMetadataParticipant> value) { this->generator = value; }

            std::shared_ptr<std::string> get_type() const { return type; }
            void set_type(std::shared_ptr<std::string> value) { this->type = value; }
        };

        class ChangeItem {
        public:
            ChangeItem() = default;
            virtual ~ChangeItem() = default;

        private:
            std::shared_ptr<std::string> field;
            std::shared_ptr<std::string> fieldtype;
            std::shared_ptr<std::string> from;
            std::shared_ptr<std::string> from_string;
            std::shared_ptr<std::string> to;
            std::shared_ptr<std::string> to_string;

        public:
            std::shared_ptr<std::string> get_field() const { return field; }
            void set_field(std::shared_ptr<std::string> value) { this->field = value; }

            std::shared_ptr<std::string> get_fieldtype() const { return fieldtype; }
            void set_fieldtype(std::shared_ptr<std::string> value) { this->fieldtype = value; }

            std::shared_ptr<std::string> get_from() const { return from; }
            void set_from(std::shared_ptr<std::string> value) { this->from = value; }

            std::shared_ptr<std::string> get_from_string() const { return from_string; }
            void set_from_string(std::shared_ptr<std::string> value) { this->from_string = value; }

            std::shared_ptr<std::string> get_to() const { return to; }
            void set_to(std::shared_ptr<std::string> value) { this->to = value; }

            std::shared_ptr<std::string> get_to_string() const { return to_string; }
            void set_to_string(std::shared_ptr<std::string> value) { this->to_string = value; }
        };

        class ChangeHistory {
        public:
            ChangeHistory() = default;
            virtual ~ChangeHistory() = default;

        private:
            std::shared_ptr<User> author;
            std::shared_ptr<std::string> created;
            std::shared_ptr<HistoryMetadata> history_metadata;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::vector<ChangeItem>> items;

        public:
            std::shared_ptr<User> get_author() const { return author; }
            void set_author(std::shared_ptr<User> value) { this->author = value; }

            std::shared_ptr<std::string> get_created() const { return created; }
            void set_created(std::shared_ptr<std::string> value) { this->created = value; }

            std::shared_ptr<HistoryMetadata> get_history_metadata() const { return history_metadata; }
            void set_history_metadata(std::shared_ptr<HistoryMetadata> value) { this->history_metadata = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::vector<ChangeItem>> get_items() const { return items; }
            void set_items(std::shared_ptr<std::vector<ChangeItem>> value) { this->items = value; }
        };

        class Changelog {
        public:
            Changelog() = default;
            virtual ~Changelog() = default;

        private:
            std::shared_ptr<std::vector<ChangeHistory>> histories;
            std::shared_ptr<int64_t> max_results;
            std::shared_ptr<int64_t> start_at;
            std::shared_ptr<int64_t> total;

        public:
            std::shared_ptr<std::vector<ChangeHistory>> get_histories() const { return histories; }
            void set_histories(std::shared_ptr<std::vector<ChangeHistory>> value) { this->histories = value; }

            std::shared_ptr<int64_t> get_max_results() const { return max_results; }
            void set_max_results(std::shared_ptr<int64_t> value) { this->max_results = value; }

            std::shared_ptr<int64_t> get_start_at() const { return start_at; }
            void set_start_at(std::shared_ptr<int64_t> value) { this->start_at = value; }

            std::shared_ptr<int64_t> get_total() const { return total; }
            void set_total(std::shared_ptr<int64_t> value) { this->total = value; }
        };

        class EditmetaFields {
        public:
            EditmetaFields() = default;
            virtual ~EditmetaFields() = default;

        private:

        public:
        };

        class EditMeta {
        public:
            EditMeta() = default;
            virtual ~EditMeta() = default;

        private:
            std::shared_ptr<EditmetaFields> fields;

        public:
            std::shared_ptr<EditmetaFields> get_fields() const { return fields; }
            void set_fields(std::shared_ptr<EditmetaFields> value) { this->fields = value; }
        };

        class IssueFields {
        public:
            IssueFields() = default;
            virtual ~IssueFields() = default;

        private:

        public:
        };

        class IssueNames {
        public:
            IssueNames() = default;
            virtual ~IssueNames() = default;

        private:

        public:
        };

        class SimpleLink {
        public:
            SimpleLink() = default;
            virtual ~SimpleLink() = default;

        private:
            std::shared_ptr<std::string> href;
            std::shared_ptr<std::string> icon_class;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> label;
            std::shared_ptr<std::string> style_class;
            std::shared_ptr<std::string> title;
            std::shared_ptr<int64_t> weight;

        public:
            std::shared_ptr<std::string> get_href() const { return href; }
            void set_href(std::shared_ptr<std::string> value) { this->href = value; }

            std::shared_ptr<std::string> get_icon_class() const { return icon_class; }
            void set_icon_class(std::shared_ptr<std::string> value) { this->icon_class = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_label() const { return label; }
            void set_label(std::shared_ptr<std::string> value) { this->label = value; }

            std::shared_ptr<std::string> get_style_class() const { return style_class; }
            void set_style_class(std::shared_ptr<std::string> value) { this->style_class = value; }

            std::shared_ptr<std::string> get_title() const { return title; }
            void set_title(std::shared_ptr<std::string> value) { this->title = value; }

            std::shared_ptr<int64_t> get_weight() const { return weight; }
            void set_weight(std::shared_ptr<int64_t> value) { this->weight = value; }
        };

        class LinkGroup {
        public:
            LinkGroup() = default;
            virtual ~LinkGroup() = default;

        private:
            std::shared_ptr<std::vector<LinkGroup>> groups;
            std::shared_ptr<SimpleLink> header;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::vector<SimpleLink>> links;
            std::shared_ptr<std::string> style_class;
            std::shared_ptr<int64_t> weight;

        public:
            std::shared_ptr<std::vector<LinkGroup>> get_groups() const { return groups; }
            void set_groups(std::shared_ptr<std::vector<LinkGroup>> value) { this->groups = value; }

            std::shared_ptr<SimpleLink> get_header() const { return header; }
            void set_header(std::shared_ptr<SimpleLink> value) { this->header = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::vector<SimpleLink>> get_links() const { return links; }
            void set_links(std::shared_ptr<std::vector<SimpleLink>> value) { this->links = value; }

            std::shared_ptr<std::string> get_style_class() const { return style_class; }
            void set_style_class(std::shared_ptr<std::string> value) { this->style_class = value; }

            std::shared_ptr<int64_t> get_weight() const { return weight; }
            void set_weight(std::shared_ptr<int64_t> value) { this->weight = value; }
        };

        class Opsbar {
        public:
            Opsbar() = default;
            virtual ~Opsbar() = default;

        private:
            std::shared_ptr<std::vector<LinkGroup>> link_groups;

        public:
            std::shared_ptr<std::vector<LinkGroup>> get_link_groups() const { return link_groups; }
            void set_link_groups(std::shared_ptr<std::vector<LinkGroup>> value) { this->link_groups = value; }
        };

        class PropertiesProperties {
        public:
            PropertiesProperties() = default;
            virtual ~PropertiesProperties() = default;

        private:

        public:
        };

        class Properties {
        public:
            Properties() = default;
            virtual ~Properties() = default;

        private:
            std::shared_ptr<PropertiesProperties> properties;

        public:
            std::shared_ptr<PropertiesProperties> get_properties() const { return properties; }
            void set_properties(std::shared_ptr<PropertiesProperties> value) { this->properties = value; }
        };

        class RenderedFields {
        public:
            RenderedFields() = default;
            virtual ~RenderedFields() = default;

        private:

        public:
        };

        class IssueSchema {
        public:
            IssueSchema() = default;
            virtual ~IssueSchema() = default;

        private:

        public:
        };

        class TransitionFields {
        public:
            TransitionFields() = default;
            virtual ~TransitionFields() = default;

        private:

        public:
        };

        class StatusCategory {
        public:
            StatusCategory() = default;
            virtual ~StatusCategory() = default;

        private:
            std::shared_ptr<std::string> color_name;
            std::shared_ptr<int64_t> id;
            std::shared_ptr<std::string> key;
            std::shared_ptr<std::string> name;
            std::shared_ptr<std::string> self;

        public:
            std::shared_ptr<std::string> get_color_name() const { return color_name; }
            void set_color_name(std::shared_ptr<std::string> value) { this->color_name = value; }

            std::shared_ptr<int64_t> get_id() const { return id; }
            void set_id(std::shared_ptr<int64_t> value) { this->id = value; }

            std::shared_ptr<std::string> get_key() const { return key; }
            void set_key(std::shared_ptr<std::string> value) { this->key = value; }

            std::shared_ptr<std::string> get_name() const { return name; }
            void set_name(std::shared_ptr<std::string> value) { this->name = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }
        };

        class Status {
        public:
            Status() = default;
            virtual ~Status() = default;

        private:
            std::shared_ptr<std::string> description;
            std::shared_ptr<std::string> icon_url;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> name;
            std::shared_ptr<std::string> self;
            std::shared_ptr<StatusCategory> status_category;
            std::shared_ptr<std::string> status_color;

        public:
            std::shared_ptr<std::string> get_description() const { return description; }
            void set_description(std::shared_ptr<std::string> value) { this->description = value; }

            std::shared_ptr<std::string> get_icon_url() const { return icon_url; }
            void set_icon_url(std::shared_ptr<std::string> value) { this->icon_url = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_name() const { return name; }
            void set_name(std::shared_ptr<std::string> value) { this->name = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }

            std::shared_ptr<StatusCategory> get_status_category() const { return status_category; }
            void set_status_category(std::shared_ptr<StatusCategory> value) { this->status_category = value; }

            std::shared_ptr<std::string> get_status_color() const { return status_color; }
            void set_status_color(std::shared_ptr<std::string> value) { this->status_color = value; }
        };

        class Transition {
        public:
            Transition() = default;
            virtual ~Transition() = default;

        private:
            std::shared_ptr<std::string> expand;
            std::shared_ptr<TransitionFields> fields;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> name;
            std::shared_ptr<Status> to;

        public:
            std::shared_ptr<std::string> get_expand() const { return expand; }
            void set_expand(std::shared_ptr<std::string> value) { this->expand = value; }

            std::shared_ptr<TransitionFields> get_fields() const { return fields; }
            void set_fields(std::shared_ptr<TransitionFields> value) { this->fields = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_name() const { return name; }
            void set_name(std::shared_ptr<std::string> value) { this->name = value; }

            std::shared_ptr<Status> get_to() const { return to; }
            void set_to(std::shared_ptr<Status> value) { this->to = value; }
        };

        class VersionedRepresentations {
        public:
            VersionedRepresentations() = default;
            virtual ~VersionedRepresentations() = default;

        private:

        public:
        };

        class Issue {
        public:
            Issue() = default;
            virtual ~Issue() = default;

        private:
            std::shared_ptr<Changelog> changelog;
            std::shared_ptr<EditMeta> editmeta;
            std::shared_ptr<std::string> expand;
            std::shared_ptr<IssueFields> fields;
            std::shared_ptr<std::map<std::string, nlohmann::json>> fields_to_include;
            std::shared_ptr<std::string> id;
            std::shared_ptr<std::string> key;
            std::shared_ptr<IssueNames> names;
            std::shared_ptr<Opsbar> operations;
            std::shared_ptr<Properties> properties;
            std::shared_ptr<RenderedFields> rendered_fields;
            std::shared_ptr<IssueSchema> schema;
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

            std::shared_ptr<IssueFields> get_fields() const { return fields; }
            void set_fields(std::shared_ptr<IssueFields> value) { this->fields = value; }

            std::shared_ptr<std::map<std::string, nlohmann::json>> get_fields_to_include() const { return fields_to_include; }
            void set_fields_to_include(std::shared_ptr<std::map<std::string, nlohmann::json>> value) { this->fields_to_include = value; }

            std::shared_ptr<std::string> get_id() const { return id; }
            void set_id(std::shared_ptr<std::string> value) { this->id = value; }

            std::shared_ptr<std::string> get_key() const { return key; }
            void set_key(std::shared_ptr<std::string> value) { this->key = value; }

            std::shared_ptr<IssueNames> get_names() const { return names; }
            void set_names(std::shared_ptr<IssueNames> value) { this->names = value; }

            std::shared_ptr<Opsbar> get_operations() const { return operations; }
            void set_operations(std::shared_ptr<Opsbar> value) { this->operations = value; }

            std::shared_ptr<Properties> get_properties() const { return properties; }
            void set_properties(std::shared_ptr<Properties> value) { this->properties = value; }

            std::shared_ptr<RenderedFields> get_rendered_fields() const { return rendered_fields; }
            void set_rendered_fields(std::shared_ptr<RenderedFields> value) { this->rendered_fields = value; }

            std::shared_ptr<IssueSchema> get_schema() const { return schema; }
            void set_schema(std::shared_ptr<IssueSchema> value) { this->schema = value; }

            std::shared_ptr<std::string> get_self() const { return self; }
            void set_self(std::shared_ptr<std::string> value) { this->self = value; }

            std::shared_ptr<std::vector<Transition>> get_transitions() const { return transitions; }
            void set_transitions(std::shared_ptr<std::vector<Transition>> value) { this->transitions = value; }

            std::shared_ptr<VersionedRepresentations> get_versioned_representations() const { return versioned_representations; }
            void set_versioned_representations(std::shared_ptr<VersionedRepresentations> value) { this->versioned_representations = value; }
        };

        class SearchResultsNames {
        public:
            SearchResultsNames() = default;
            virtual ~SearchResultsNames() = default;

        private:

        public:
        };

        class SearchResultsSchema {
        public:
            SearchResultsSchema() = default;
            virtual ~SearchResultsSchema() = default;

        private:

        public:
        };

        class SearchResults {
        public:
            SearchResults() = default;
            virtual ~SearchResults() = default;

        private:
            std::shared_ptr<std::string> expand;
            std::shared_ptr<std::vector<Issue>> issues;
            std::shared_ptr<int64_t> max_results;
            std::shared_ptr<SearchResultsNames> names;
            std::shared_ptr<SearchResultsSchema> schema;
            std::shared_ptr<int64_t> start_at;
            std::shared_ptr<int64_t> total;
            std::shared_ptr<std::vector<std::string>> warning_messages;

        public:
            std::shared_ptr<std::string> get_expand() const { return expand; }
            void set_expand(std::shared_ptr<std::string> value) { this->expand = value; }

            std::shared_ptr<std::vector<Issue>> get_issues() const { return issues; }
            void set_issues(std::shared_ptr<std::vector<Issue>> value) { this->issues = value; }

            std::shared_ptr<int64_t> get_max_results() const { return max_results; }
            void set_max_results(std::shared_ptr<int64_t> value) { this->max_results = value; }

            std::shared_ptr<SearchResultsNames> get_names() const { return names; }
            void set_names(std::shared_ptr<SearchResultsNames> value) { this->names = value; }

            std::shared_ptr<SearchResultsSchema> get_schema() const { return schema; }
            void set_schema(std::shared_ptr<SearchResultsSchema> value) { this->schema = value; }

            std::shared_ptr<int64_t> get_start_at() const { return start_at; }
            void set_start_at(std::shared_ptr<int64_t> value) { this->start_at = value; }

            std::shared_ptr<int64_t> get_total() const { return total; }
            void set_total(std::shared_ptr<int64_t> value) { this->total = value; }

            std::shared_ptr<std::vector<std::string>> get_warning_messages() const { return warning_messages; }
            void set_warning_messages(std::shared_ptr<std::vector<std::string>> value) { this->warning_messages = value; }
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

    void from_json(const json& j, Jira::Data::IssueFields& x);
    void to_json(json& j, const Jira::Data::IssueFields& x);

    void from_json(const json& j, Jira::Data::IssueNames& x);
    void to_json(json& j, const Jira::Data::IssueNames& x);

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

    void from_json(const json& j, Jira::Data::IssueSchema& x);
    void to_json(json& j, const Jira::Data::IssueSchema& x);

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

    void from_json(const json& j, Jira::Data::Issue& x);
    void to_json(json& j, const Jira::Data::Issue& x);

    void from_json(const json& j, Jira::Data::SearchResultsNames& x);
    void to_json(json& j, const Jira::Data::SearchResultsNames& x);

    void from_json(const json& j, Jira::Data::SearchResultsSchema& x);
    void to_json(json& j, const Jira::Data::SearchResultsSchema& x);

    void from_json(const json& j, Jira::Data::SearchResults& x);
    void to_json(json& j, const Jira::Data::SearchResults& x);

    inline void from_json(const json& j, Jira::Data::AvatarUrls& x) {
    }

    inline void to_json(json& j, const Jira::Data::AvatarUrls& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::User& x) {
        x.set_active(j.at("active").get<bool>());
        x.set_avatar_urls(Jira::Data::get_optional<Jira::Data::AvatarUrls>(j, "avatarUrls"));
        x.set_display_name(Jira::Data::get_optional<std::string>(j, "displayName"));
        x.set_email_address(Jira::Data::get_optional<std::string>(j, "emailAddress"));
        x.set_key(Jira::Data::get_optional<std::string>(j, "key"));
        x.set_name(Jira::Data::get_optional<std::string>(j, "name"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
        x.set_time_zone(Jira::Data::get_optional<std::string>(j, "timeZone"));
    }

    inline void to_json(json& j, const Jira::Data::User& x) {
        j = json::object();
        j["active"] = x.get_active();
        j["avatarUrls"] = x.get_avatar_urls();
        j["displayName"] = x.get_display_name();
        j["emailAddress"] = x.get_email_address();
        j["key"] = x.get_key();
        j["name"] = x.get_name();
        j["self"] = x.get_self();
        j["timeZone"] = x.get_time_zone();
    }

    inline void from_json(const json& j, Jira::Data::HistoryMetadataParticipant& x) {
        x.set_avatar_url(Jira::Data::get_optional<std::string>(j, "avatarUrl"));
        x.set_display_name(Jira::Data::get_optional<std::string>(j, "displayName"));
        x.set_display_name_key(Jira::Data::get_optional<std::string>(j, "displayNameKey"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_type(Jira::Data::get_optional<std::string>(j, "type"));
        x.set_url(Jira::Data::get_optional<std::string>(j, "url"));
    }

    inline void to_json(json& j, const Jira::Data::HistoryMetadataParticipant& x) {
        j = json::object();
        j["avatarUrl"] = x.get_avatar_url();
        j["displayName"] = x.get_display_name();
        j["displayNameKey"] = x.get_display_name_key();
        j["id"] = x.get_id();
        j["type"] = x.get_type();
        j["url"] = x.get_url();
    }

    inline void from_json(const json& j, Jira::Data::ExtraData& x) {
    }

    inline void to_json(json& j, const Jira::Data::ExtraData& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::HistoryMetadata& x) {
        x.set_activity_description(Jira::Data::get_optional<std::string>(j, "activityDescription"));
        x.set_activity_description_key(Jira::Data::get_optional<std::string>(j, "activityDescriptionKey"));
        x.set_actor(Jira::Data::get_optional<Jira::Data::HistoryMetadataParticipant>(j, "actor"));
        x.set_cause(Jira::Data::get_optional<Jira::Data::HistoryMetadataParticipant>(j, "cause"));
        x.set_description(Jira::Data::get_optional<std::string>(j, "description"));
        x.set_description_key(Jira::Data::get_optional<std::string>(j, "descriptionKey"));
        x.set_email_description(Jira::Data::get_optional<std::string>(j, "emailDescription"));
        x.set_email_description_key(Jira::Data::get_optional<std::string>(j, "emailDescriptionKey"));
        x.set_extra_data(Jira::Data::get_optional<Jira::Data::ExtraData>(j, "extraData"));
        x.set_generator(Jira::Data::get_optional<Jira::Data::HistoryMetadataParticipant>(j, "generator"));
        x.set_type(Jira::Data::get_optional<std::string>(j, "type"));
    }

    inline void to_json(json& j, const Jira::Data::HistoryMetadata& x) {
        j = json::object();
        j["activityDescription"] = x.get_activity_description();
        j["activityDescriptionKey"] = x.get_activity_description_key();
        j["actor"] = x.get_actor();
        j["cause"] = x.get_cause();
        j["description"] = x.get_description();
        j["descriptionKey"] = x.get_description_key();
        j["emailDescription"] = x.get_email_description();
        j["emailDescriptionKey"] = x.get_email_description_key();
        j["extraData"] = x.get_extra_data();
        j["generator"] = x.get_generator();
        j["type"] = x.get_type();
    }

    inline void from_json(const json& j, Jira::Data::ChangeItem& x) {
        x.set_field(Jira::Data::get_optional<std::string>(j, "field"));
        x.set_fieldtype(Jira::Data::get_optional<std::string>(j, "fieldtype"));
        x.set_from(Jira::Data::get_optional<std::string>(j, "from"));
        x.set_from_string(Jira::Data::get_optional<std::string>(j, "fromString"));
        x.set_to(Jira::Data::get_optional<std::string>(j, "to"));
        x.set_to_string(Jira::Data::get_optional<std::string>(j, "toString"));
    }

    inline void to_json(json& j, const Jira::Data::ChangeItem& x) {
        j = json::object();
        j["field"] = x.get_field();
        j["fieldtype"] = x.get_fieldtype();
        j["from"] = x.get_from();
        j["fromString"] = x.get_from_string();
        j["to"] = x.get_to();
        j["toString"] = x.get_to_string();
    }

    inline void from_json(const json& j, Jira::Data::ChangeHistory& x) {
        x.set_author(Jira::Data::get_optional<Jira::Data::User>(j, "author"));
        x.set_created(Jira::Data::get_optional<std::string>(j, "created"));
        x.set_history_metadata(Jira::Data::get_optional<Jira::Data::HistoryMetadata>(j, "historyMetadata"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_items(Jira::Data::get_optional<std::vector<Jira::Data::ChangeItem>>(j, "items"));
    }

    inline void to_json(json& j, const Jira::Data::ChangeHistory& x) {
        j = json::object();
        j["author"] = x.get_author();
        j["created"] = x.get_created();
        j["historyMetadata"] = x.get_history_metadata();
        j["id"] = x.get_id();
        j["items"] = x.get_items();
    }

    inline void from_json(const json& j, Jira::Data::Changelog& x) {
        x.set_histories(Jira::Data::get_optional<std::vector<Jira::Data::ChangeHistory>>(j, "histories"));
        x.set_max_results(Jira::Data::get_optional<int64_t>(j, "maxResults"));
        x.set_start_at(Jira::Data::get_optional<int64_t>(j, "startAt"));
        x.set_total(Jira::Data::get_optional<int64_t>(j, "total"));
    }

    inline void to_json(json& j, const Jira::Data::Changelog& x) {
        j = json::object();
        j["histories"] = x.get_histories();
        j["maxResults"] = x.get_max_results();
        j["startAt"] = x.get_start_at();
        j["total"] = x.get_total();
    }

    inline void from_json(const json& j, Jira::Data::EditmetaFields& x) {
    }

    inline void to_json(json& j, const Jira::Data::EditmetaFields& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::EditMeta& x) {
        x.set_fields(Jira::Data::get_optional<Jira::Data::EditmetaFields>(j, "fields"));
    }

    inline void to_json(json& j, const Jira::Data::EditMeta& x) {
        j = json::object();
        j["fields"] = x.get_fields();
    }

    inline void from_json(const json& j, Jira::Data::IssueFields& x) {
    }

    inline void to_json(json& j, const Jira::Data::IssueFields& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::IssueNames& x) {
    }

    inline void to_json(json& j, const Jira::Data::IssueNames& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::SimpleLink& x) {
        x.set_href(Jira::Data::get_optional<std::string>(j, "href"));
        x.set_icon_class(Jira::Data::get_optional<std::string>(j, "iconClass"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_label(Jira::Data::get_optional<std::string>(j, "label"));
        x.set_style_class(Jira::Data::get_optional<std::string>(j, "styleClass"));
        x.set_title(Jira::Data::get_optional<std::string>(j, "title"));
        x.set_weight(Jira::Data::get_optional<int64_t>(j, "weight"));
    }

    inline void to_json(json& j, const Jira::Data::SimpleLink& x) {
        j = json::object();
        j["href"] = x.get_href();
        j["iconClass"] = x.get_icon_class();
        j["id"] = x.get_id();
        j["label"] = x.get_label();
        j["styleClass"] = x.get_style_class();
        j["title"] = x.get_title();
        j["weight"] = x.get_weight();
    }

    inline void from_json(const json& j, Jira::Data::LinkGroup& x) {
        x.set_groups(Jira::Data::get_optional<std::vector<Jira::Data::LinkGroup>>(j, "groups"));
        x.set_header(Jira::Data::get_optional<Jira::Data::SimpleLink>(j, "header"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_links(Jira::Data::get_optional<std::vector<Jira::Data::SimpleLink>>(j, "links"));
        x.set_style_class(Jira::Data::get_optional<std::string>(j, "styleClass"));
        x.set_weight(Jira::Data::get_optional<int64_t>(j, "weight"));
    }

    inline void to_json(json& j, const Jira::Data::LinkGroup& x) {
        j = json::object();
        j["groups"] = x.get_groups();
        j["header"] = x.get_header();
        j["id"] = x.get_id();
        j["links"] = x.get_links();
        j["styleClass"] = x.get_style_class();
        j["weight"] = x.get_weight();
    }

    inline void from_json(const json& j, Jira::Data::Opsbar& x) {
        x.set_link_groups(Jira::Data::get_optional<std::vector<Jira::Data::LinkGroup>>(j, "linkGroups"));
    }

    inline void to_json(json& j, const Jira::Data::Opsbar& x) {
        j = json::object();
        j["linkGroups"] = x.get_link_groups();
    }

    inline void from_json(const json& j, Jira::Data::PropertiesProperties& x) {
    }

    inline void to_json(json& j, const Jira::Data::PropertiesProperties& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::Properties& x) {
        x.set_properties(Jira::Data::get_optional<Jira::Data::PropertiesProperties>(j, "properties"));
    }

    inline void to_json(json& j, const Jira::Data::Properties& x) {
        j = json::object();
        j["properties"] = x.get_properties();
    }

    inline void from_json(const json& j, Jira::Data::RenderedFields& x) {
    }

    inline void to_json(json& j, const Jira::Data::RenderedFields& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::IssueSchema& x) {
    }

    inline void to_json(json& j, const Jira::Data::IssueSchema& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::TransitionFields& x) {
    }

    inline void to_json(json& j, const Jira::Data::TransitionFields& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::StatusCategory& x) {
        x.set_color_name(Jira::Data::get_optional<std::string>(j, "colorName"));
        x.set_id(Jira::Data::get_optional<int64_t>(j, "id"));
        x.set_key(Jira::Data::get_optional<std::string>(j, "key"));
        x.set_name(Jira::Data::get_optional<std::string>(j, "name"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
    }

    inline void to_json(json& j, const Jira::Data::StatusCategory& x) {
        j = json::object();
        j["colorName"] = x.get_color_name();
        j["id"] = x.get_id();
        j["key"] = x.get_key();
        j["name"] = x.get_name();
        j["self"] = x.get_self();
    }

    inline void from_json(const json& j, Jira::Data::Status& x) {
        x.set_description(Jira::Data::get_optional<std::string>(j, "description"));
        x.set_icon_url(Jira::Data::get_optional<std::string>(j, "iconUrl"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_name(Jira::Data::get_optional<std::string>(j, "name"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
        x.set_status_category(Jira::Data::get_optional<Jira::Data::StatusCategory>(j, "statusCategory"));
        x.set_status_color(Jira::Data::get_optional<std::string>(j, "statusColor"));
    }

    inline void to_json(json& j, const Jira::Data::Status& x) {
        j = json::object();
        j["description"] = x.get_description();
        j["iconUrl"] = x.get_icon_url();
        j["id"] = x.get_id();
        j["name"] = x.get_name();
        j["self"] = x.get_self();
        j["statusCategory"] = x.get_status_category();
        j["statusColor"] = x.get_status_color();
    }

    inline void from_json(const json& j, Jira::Data::Transition& x) {
        x.set_expand(Jira::Data::get_optional<std::string>(j, "expand"));
        x.set_fields(Jira::Data::get_optional<Jira::Data::TransitionFields>(j, "fields"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_name(Jira::Data::get_optional<std::string>(j, "name"));
        x.set_to(Jira::Data::get_optional<Jira::Data::Status>(j, "to"));
    }

    inline void to_json(json& j, const Jira::Data::Transition& x) {
        j = json::object();
        j["expand"] = x.get_expand();
        j["fields"] = x.get_fields();
        j["id"] = x.get_id();
        j["name"] = x.get_name();
        j["to"] = x.get_to();
    }

    inline void from_json(const json& j, Jira::Data::VersionedRepresentations& x) {
    }

    inline void to_json(json& j, const Jira::Data::VersionedRepresentations& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::Issue& x) {
        x.set_changelog(Jira::Data::get_optional<Jira::Data::Changelog>(j, "changelog"));
        x.set_editmeta(Jira::Data::get_optional<Jira::Data::EditMeta>(j, "editmeta"));
        x.set_expand(Jira::Data::get_optional<std::string>(j, "expand"));
        x.set_fields(Jira::Data::get_optional<Jira::Data::IssueFields>(j, "fields"));
        x.set_fields_to_include(Jira::Data::get_optional<std::map<std::string, json>>(j, "fieldsToInclude"));
        x.set_id(Jira::Data::get_optional<std::string>(j, "id"));
        x.set_key(Jira::Data::get_optional<std::string>(j, "key"));
        x.set_names(Jira::Data::get_optional<Jira::Data::IssueNames>(j, "names"));
        x.set_operations(Jira::Data::get_optional<Jira::Data::Opsbar>(j, "operations"));
        x.set_properties(Jira::Data::get_optional<Jira::Data::Properties>(j, "properties"));
        x.set_rendered_fields(Jira::Data::get_optional<Jira::Data::RenderedFields>(j, "renderedFields"));
        x.set_schema(Jira::Data::get_optional<Jira::Data::IssueSchema>(j, "schema"));
        x.set_self(Jira::Data::get_optional<std::string>(j, "self"));
        x.set_transitions(Jira::Data::get_optional<std::vector<Jira::Data::Transition>>(j, "transitions"));
        x.set_versioned_representations(Jira::Data::get_optional<Jira::Data::VersionedRepresentations>(j, "versionedRepresentations"));
    }

    inline void to_json(json& j, const Jira::Data::Issue& x) {
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

    inline void from_json(const json& j, Jira::Data::SearchResultsNames& x) {
    }

    inline void to_json(json& j, const Jira::Data::SearchResultsNames& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::SearchResultsSchema& x) {
    }

    inline void to_json(json& j, const Jira::Data::SearchResultsSchema& x) {
        j = json::object();
    }

    inline void from_json(const json& j, Jira::Data::SearchResults& x) {
        x.set_expand(Jira::Data::get_optional<std::string>(j, "expand"));
        x.set_issues(Jira::Data::get_optional<std::vector<Jira::Data::Issue>>(j, "issues"));
        x.set_max_results(Jira::Data::get_optional<int64_t>(j, "maxResults"));
        x.set_names(Jira::Data::get_optional<Jira::Data::SearchResultsNames>(j, "names"));
        x.set_schema(Jira::Data::get_optional<Jira::Data::SearchResultsSchema>(j, "schema"));
        x.set_start_at(Jira::Data::get_optional<int64_t>(j, "startAt"));
        x.set_total(Jira::Data::get_optional<int64_t>(j, "total"));
        x.set_warning_messages(Jira::Data::get_optional<std::vector<std::string>>(j, "warningMessages"));
    }

    inline void to_json(json& j, const Jira::Data::SearchResults& x) {
        j = json::object();
        j["expand"] = x.get_expand();
        j["issues"] = x.get_issues();
        j["maxResults"] = x.get_max_results();
        j["names"] = x.get_names();
        j["schema"] = x.get_schema();
        j["startAt"] = x.get_start_at();
        j["total"] = x.get_total();
        j["warningMessages"] = x.get_warning_messages();
    }
}

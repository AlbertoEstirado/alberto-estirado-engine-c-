
#pragma once

#include <map>
#include <string>
#include <variant.hpp>

namespace engine
{
	class Message
	{

	private:
		std::string id_;
		std::map<std::string, Variant> parameters_;

	public:

		/**
		 * @brief Message Constructor
		 *
		 * @param id The id of the message
		 */
		Message(const std::string& id) : id_(id)
		{
		}

		/**
		 * @brief Get a parameter from the message
		 *
		 * @param id The id of the message
		 */
		Variant get_Variant(const std::string id)
		{
			return parameters_[id];
		}

		/**
		 * @return The id of the message
		 *
		 */
		std::string get_Id()
		{
			return id_;
		}

		/**
		 * @brief Add a parameter to the message
		 *
		 * @param id The id of the parameter
		 *
		 * @param value The value of the parameter
		 *
		 */
		void add_Parameter(const std::string& id, const Variant& value)
		{
			parameters_[id] = value;
		}

		Variant& operator[](const std::string id)
		{
			return parameters_[id];
		}

		operator std::string() const
		{
			return id_;
		}
	};
}
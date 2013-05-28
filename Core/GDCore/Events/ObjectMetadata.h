/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */
#ifndef OBJECTMETADATA_H
#define OBJECTMETADATA_H
#include <string>
#include <map>
#include "GDCore/Events/InstructionMetadata.h"
#include "GDCore/Events/ExpressionMetadata.h"
#if defined(GD_IDE_ONLY)
#include <wx/bitmap.h>
#endif
namespace gd { class Object; }
namespace gd { class InstructionMetadata; }
namespace gd { class ExpressionMetadata; }
namespace gd { class StrExpressionMetadata; }
class wxBitmap;

typedef void (*DestroyFunPtr)(gd::Object*);
typedef gd::Object * (*CreateFunPtr)(std::string name);

namespace gd
{

/**
 * \brief Contains user-friendly information about an object type
 *
 * \ingroup Events
 */
class GD_CORE_API ObjectMetadata
{
public:
    ObjectMetadata(const std::string & extensionNamespace_,
                   const std::string & name_,
                   const std::string & fullname_,
                   const std::string & informations_,
                   const std::string & icon24x24_,
                   CreateFunPtr createFunPtrP,
                   DestroyFunPtr destroyFunPtrP,
                   const std::string & cppClassName_);
    ObjectMetadata() : createFunPtr(NULL), destroyFunPtr(NULL) {}
    virtual ~ObjectMetadata() {};

    /**
     * Declare a new condition as being part of the extension.
     * \note This method does nothing when used for GD C++ runtime.
     */
    gd::InstructionMetadata & AddCondition(const std::string & name_,
                                           const std::string & fullname_,
                                           const std::string & description_,
                                           const std::string & sentence_,
                                           const std::string & group_,
                                           const std::string & icon_,
                                           const std::string & smallicon_);

    /**
     * Declare a new action as being part of the extension.
     * \note This method does nothing when used for GD C++ runtime.
     */
    gd::InstructionMetadata & AddAction(const std::string & name_,
                                           const std::string & fullname_,
                                           const std::string & description_,
                                           const std::string & sentence_,
                                           const std::string & group_,
                                           const std::string & icon_,
                                           const std::string & smallicon_);
    /**
     * Declare a new expression as being part of the extension.
     * \note This method does nothing when used for GD C++ runtime.
     */
    gd::ExpressionMetadata & AddExpression(const std::string & name_,
                                           const std::string & fullname_,
                                           const std::string & description_,
                                           const std::string & group_,
                                           const std::string & smallicon_);
    /**
     * Declare a new string expression as being part of the extension.
     * \note This method does nothing when used for GD C++ runtime.
     */
    gd::StrExpressionMetadata & AddStrExpression(const std::string & name_,
                                           const std::string & fullname_,
                                           const std::string & description_,
                                           const std::string & group_,
                                           const std::string & smallicon_);

    /**
     * Set the name shown to the user.
     * \note This method does nothing when used for GD C++ runtime.
     */
    ObjectMetadata & SetFullName(const std::string & fullname_);

    /**
     * Set the description shown to the user.
     * \note This method does nothing when used for GD C++ runtime.
     */
    ObjectMetadata & SetDescription(const std::string & description_);

    /**
     * Set the bitmap icon shown to the user.
     * \note This method does nothing when used for GD C++ runtime.
     */
    ObjectMetadata & SetBitmapIcon(const wxBitmap & bitmap_);

    const std::string & GetName() const { return name; }
#if defined(GD_IDE_ONLY)
    const std::string & GetFullName() const { return fullname; }
    const std::string & GetDescription() const { return description; }
    const wxBitmap & GetBitmapIcon() const { return icon; }
#endif

    /**
     * Set that the object is located in a specific include file
     * \note This method does nothing when used for GD C++ runtime.
     */
    ObjectMetadata & SetIncludeFile(const std::string & includeFile);

#if defined(GD_IDE_ONLY)
    std::map<std::string, gd::InstructionMetadata > conditionsInfos;
    std::map<std::string, gd::InstructionMetadata > actionsInfos;
    std::map<std::string, gd::ExpressionMetadata > expressionsInfos;
    std::map<std::string, gd::StrExpressionMetadata > strExpressionsInfos;

    std::string optionalIncludeFile;
    std::string cppClassName;
#endif
    CreateFunPtr createFunPtr;
    DestroyFunPtr destroyFunPtr;
private:
    std::string extensionNamespace;
    std::string name;
#if defined(GD_IDE_ONLY)
    std::string fullname;
    std::string description;
    wxBitmap icon;
#endif
};


}
#endif // OBJECTMETADATA_H

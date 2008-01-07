#ifndef CondFormats_L1TObjects_L1GtEnergySumTemplate_h
#define CondFormats_L1TObjects_L1GtEnergySumTemplate_h

/**
 * \class L1GtEnergySumTemplate
 * 
 * 
 * Description: L1 Global Trigger energy-sum template.  
 *
 * Implementation:
 *    <TODO: enter implementation details>
 *   
 * \author: Vasile Mihai Ghete - HEPHY Vienna
 * 
 * $Date$
 * $Revision$
 *
 */

// system include files
#include <string>
#include <iosfwd>

#include <boost/cstdint.hpp>

// user include files

//   base class
#include "CondFormats/L1TObjects/interface/L1GtCondition.h"

// forward declarations

// class declaration
class L1GtEnergySumTemplate : public L1GtCondition
{

public:

    // constructor
    L1GtEnergySumTemplate();

    // constructor
    L1GtEnergySumTemplate(const std::string&);

    // constructor
    L1GtEnergySumTemplate(const std::string&, const L1GtConditionType&);

    // copy constructor
    L1GtEnergySumTemplate(const L1GtEnergySumTemplate&);

    // destructor
    virtual ~L1GtEnergySumTemplate();

    // assign operator
    L1GtEnergySumTemplate& operator=(const L1GtEnergySumTemplate&);

public:

    /// typedef for a single object template
    typedef struct
    {
        unsigned int etThreshold;
        bool energyOverflow;

        // used only for ETM
        boost::uint64_t phiRange0Word; // ETM phi has 72 bins - two 64-bits words
        boost::uint64_t phiRange1Word;
    } ObjectParameter;

public:

    inline const std::vector<ObjectParameter>* objectParameter() const {
        return &m_objectParameter;
    }

    /// set functions
    void setConditionParameter(const std::vector<ObjectParameter>&);

    /// print the condition
    virtual void print(std::ostream& myCout) const;

private:

    /// copy function for copy constructor and operator=
    void copy(const L1GtEnergySumTemplate& cp);

private:

    /// variables containing the parameters
    std::vector<ObjectParameter> m_objectParameter;

};

#endif
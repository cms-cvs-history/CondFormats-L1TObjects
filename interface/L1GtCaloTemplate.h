#ifndef CondFormats_L1TObjects_L1GtCaloTemplate_h
#define CondFormats_L1TObjects_L1GtCaloTemplate_h

/**
 * \class L1GtCaloTemplate
 * 
 * 
 * Description: L1 Global Trigger calo template.  
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
class L1GtCaloTemplate : public L1GtCondition
{

public:

    // constructor
    L1GtCaloTemplate();

    // constructor
    L1GtCaloTemplate(const std::string& );

    // constructor
    L1GtCaloTemplate(const std::string&, const L1GtConditionType& );

    // copy constructor
    L1GtCaloTemplate( const L1GtCaloTemplate& );

    // destructor
    virtual ~L1GtCaloTemplate();

    // assign operator
    L1GtCaloTemplate& operator= (const L1GtCaloTemplate&);

public:

    /// typedef for a single object template
    typedef struct
    {
        unsigned int etThreshold;
        unsigned int etaRange;
        unsigned int phiRange;
    }
    ObjectParameter;

    /// typedef for correlation parameters
    typedef struct
    {
        boost::uint64_t deltaEtaRange;

        boost::uint64_t deltaPhiRange;
        unsigned int deltaPhiMaxbits;
    }
    CorrelationParameter;


public:

    inline const std::vector<ObjectParameter>* objectParameter() const
    {
        return &m_objectParameter;
    }

    inline const CorrelationParameter* correlationParameter() const
    {
        return &m_correlationParameter;
    }


    /// set functions
    void setConditionParameter(const std::vector<ObjectParameter>& objParameter,
                               const CorrelationParameter& corrParameter);


    /// print the condition
    virtual void print(std::ostream& myCout) const;

protected:

    /// copy function for copy constructor and operator=
    void copy( const L1GtCaloTemplate& cp);


protected:

    /// variables containing the parameters
    std::vector<ObjectParameter> m_objectParameter;
    CorrelationParameter m_correlationParameter;

};

#endif

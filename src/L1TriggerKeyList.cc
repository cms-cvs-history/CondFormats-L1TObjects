// -*- C++ -*-
//
// Package:     L1TObjects
// Class  :     L1TriggerKeyList
// 
// Implementation:
//     <Notes on implementation>
//
// Original Author:  
//         Created:  Fri Feb 29 21:00:24 CET 2008
// $Id: L1TriggerKeyList.cc,v 1.1 2008/03/03 07:31:07 wsun Exp $
//

// system include files

// user include files
#include "CondFormats/L1TObjects/interface/L1TriggerKeyList.h"


//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
L1TriggerKeyList::L1TriggerKeyList()
{
}

// L1TriggerKeyList::L1TriggerKeyList(const L1TriggerKeyList& rhs)
// {
//    // do actual copying here;
// }

L1TriggerKeyList::~L1TriggerKeyList()
{
}

//
// assignment operators
//
// const L1TriggerKeyList& L1TriggerKeyList::operator=(const L1TriggerKeyList& rhs)
// {
//   //An exception safe implementation is
//   L1TriggerKeyList temp(rhs);
//   swap(rhs);
//
//   return *this;
// }

//
// member functions
//

bool
L1TriggerKeyList::addKey( const std::string& tscKey,
			  const std::string& payloadToken,
			  bool overwriteKey )
{
  std::pair< KeyToToken::iterator, bool > result =
    m_tscKeyToToken.insert( std::make_pair( tscKey, payloadToken ) ) ;

  if( !result.second && overwriteKey )
    {
      // Erase previous entry
      m_tscKeyToToken.erase( result.first ) ;

      // Try again
      result = m_tscKeyToToken.insert( std::make_pair( tscKey,
						       payloadToken ) ) ;
    }

  return result.second ;
}

bool
L1TriggerKeyList::addKey( const std::string& recordType,
			  const std::string& key,
			  const std::string& payloadToken,
			  bool overwriteKey )
{
  RecordToKeyToToken::iterator it = m_recordKeyToken.find( recordType ) ;

  if( it == m_recordKeyToken.end() )
    {
      it = m_recordKeyToken.insert( std::make_pair( recordType,
						    KeyToToken() ) ).first ;
    } 

  std::pair< KeyToToken::iterator, bool > result =
    it->second.insert( std::make_pair( key, payloadToken ) ) ;

  if( !result.second && overwriteKey )
    {
      // Erase previous entry
      it->second.erase( result.first ) ;

      // Try again
      result = it->second.insert( std::make_pair( key, payloadToken ) ) ;
    }

  return result.second ;
}

//
// const member functions
//

std::string
L1TriggerKeyList::token( const std::string& tscKey ) const
{
  KeyToToken::const_iterator it = m_tscKeyToToken.find( tscKey ) ;

  if( it == m_tscKeyToToken.end() )
    {
      return std::string() ;
    }
  else
    {
      return it->second;
    }
}

std::string
L1TriggerKeyList::token( const std::string& recordName,
			 const std::string& dataType,
			 const std::string& key ) const
{
  std::string recordType = recordName + "@" + dataType ;
  return token( recordType, key ) ;
}

std::string
L1TriggerKeyList::token( const std::string& recordType,
			 const std::string& key ) const
{
  RecordToKeyToToken::const_iterator it = m_recordKeyToken.find( recordType ) ;

  if( it == m_recordKeyToken.end() )
    {
      return std::string() ;
    } 
  else
    {
      KeyToToken::const_iterator it2 = it->second.find( key ) ;

      if( it2 == it->second.end() )
	{
	  return std::string() ;
	}
      else
	{
	  return it2->second ;
	}
    }
}

//
// static member functions
//

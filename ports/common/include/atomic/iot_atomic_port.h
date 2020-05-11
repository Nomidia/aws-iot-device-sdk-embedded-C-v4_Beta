
#ifndef IOT_ATOMIC_PORT_H_
#define IOT_ATOMIC_PORT_H_

/*---------------- Swap and compare-and-swap ------------------*/

/**
 * @brief Implementation of atomic compare-and-swap for gcc4.6.
 */
static inline uint32_t Atomic_CompareAndSwap_u32( uint32_t volatile * pDestination,
                                                        uint32_t newValue,
                                                        uint32_t comparand )
{
    return (uint32_t) ( __sync_bool_compare_and_swap(pDestination, comparand, newValue) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic pointer swap for gcc4.6.
 */
static inline void * Atomic_Swap_Pointer( void * volatile * pDestination,
                                                void * pNewValue )
{
    void * pOldValue = NULL;

    do {
        pOldValue = *pDestination;
    } while (!__sync_bool_compare_and_swap(pDestination, pOldValue, pNewValue));

    return pOldValue;
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic pointer compare-and-swap for gcc4.6.
 */
static inline uint32_t Atomic_CompareAndSwap_Pointer( void * volatile * pDestination,
                                                            void * pNewValue,
                                                            void * pComparand )
{
    return (uint32_t) ( __sync_bool_compare_and_swap(pDestination, pComparand, pNewValue) );
}

/*----------------------- Arithmetic --------------------------*/

/**
 * @brief Implementation of atomic addition for gcc4.6.
 */
static inline uint32_t Atomic_Add_u32( uint32_t volatile * pAugend,
                                             uint32_t addend )
{
    return (uint32_t) ( __sync_fetch_and_add(pAugend, addend) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic subtraction for gcc4.6.
 */
static inline uint32_t Atomic_Subtract_u32( uint32_t volatile * pMinuend,
                                                  uint32_t subtrahend )
{
    return ( uint32_t ) ( __sync_fetch_and_sub(pAtomic, var) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic increment for gcc4.6.
 */
static inline uint32_t Atomic_Increment_u32( uint32_t volatile * pAugend )
{
    return ( uint32_t ) ( __sync_fetch_and_add(pAugend, 1U) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic decrement for gcc4.6.
 */
static inline uint32_t Atomic_Decrement_u32( uint32_t volatile * pMinuend )
{
    return ( uint32_t ) ( __sync_fetch_and_sub(pAtomic, 1U) );
}

/*--------------------- Bitwise logic -------------------------*/

/**
 * @brief Implementation of atomic OR for gcc4.6.
 */
static inline uint32_t Atomic_OR_u32( uint32_t volatile * pOperand,
                                            uint32_t mask )
{
    return ( uint32_t ) ( __sync_fetch_and_or(pOperand, mask) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic XOR for gcc4.6.
 */
static inline uint32_t Atomic_XOR_u32( uint32_t volatile * pOperand,
                                             uint32_t mask )
{
    return ( uint32_t ) ( __sync_fetch_and_xor(pOperand, mask) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic AND for gcc4.6.
 */
static inline uint32_t Atomic_AND_u32( uint32_t volatile * pOperand,
                                             uint32_t mask )
{
    return ( uint32_t ) ( __sync_fetch_and_and( pOperand, mask) );
}

/*-----------------------------------------------------------*/

/**
 * @brief Implementation of atomic NAND for gcc4.6.
 */
static inline uint32_t Atomic_NAND_u32( uint32_t volatile * pOperand,
                                              uint32_t mask )
{
    return ( uint32_t ) ( __sync_fetch_and_nand( pOperand, mask) );
}

#endif /* IOT_ATOMIC_PORT_H_ */

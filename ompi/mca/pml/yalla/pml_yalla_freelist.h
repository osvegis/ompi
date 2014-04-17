/**
* Copyright (C) Mellanox Technologies Ltd. 2001-2014.  ALL RIGHTS RESERVED.
* This software product is a proprietary product of Mellanox Technologies Ltd.
* (the "Company") and all right, title, and interest and to the software product,
* including all associated intellectual property rights, are and shall
* remain exclusively with the Company.
*
* This software product is governed by the End User License Agreement
* provided with the software product.
* $COPYRIGHT$
* $HEADER$
*/

#ifndef PML_YALLA_FREELIST_H_
#define PML_YALLA_FREELIST_H_

#include "ompi_config.h"
#include "opal/class/opal_free_list.h"


#define mca_pml_yalla_freelist_t opal_free_list_t

#define PML_YALLA_FREELIST_GET(_freelist) \
    ({ \
        opal_free_list_item_t *item; \
        int rc; \
        OPAL_FREE_LIST_GET(_freelist, item, rc); \
        (void*)(item); \
    })

#define PML_YALLA_FREELIST_RETURN(_freelist, _item) \
    { \
        OPAL_FREE_LIST_RETURN(_freelist, _item); \
    }

#define PML_YALLA_FREELIST_INIT(_fl, _type, _initial, _max, _batch) \
    opal_free_list_init(_fl, sizeof(_type), OBJ_CLASS(_type), \
                        _initial, _max, _batch);

#endif /* PML_YALLA_FREELIST_H_ */

<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPPur;

use PHPExiftool\Driver\AbstractTag;

class ExclusivityEndDate extends AbstractTag
{

    protected $Id = 'exclusivityEndDate';

    protected $Name = 'ExclusivityEndDate';

    protected $FullName = 'XMP::pur';

    protected $GroupName = 'XMP-pur';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-pur';

    protected $g2 = 'Document';

    protected $Type = 'date';

    protected $Writable = true;

    protected $Description = 'Exclusivity End Date';

    protected $local_g2 = 'Time';

    protected $flag_Avoid = true;

    protected $flag_List = true;

    protected $flag_Bag = true;

}

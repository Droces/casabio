<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\PDF;

use PHPExiftool\Driver\AbstractTag;

class SigningDate extends AbstractTag
{

    protected $Id = 'M';

    protected $Name = 'SigningDate';

    protected $FullName = 'PDF::Signature';

    protected $GroupName = 'PDF';

    protected $g0 = 'PDF';

    protected $g1 = 'PDF';

    protected $g2 = 'Document';

    protected $Type = 'date';

    protected $Writable = false;

    protected $Description = 'Signing Date';

    protected $local_g2 = 'Time';

}
